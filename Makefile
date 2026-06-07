# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/05 21:36:59 by bpetrovi          #+#    #+#              #
#    Updated: 2026/06/07 23:36:44 by bpetrovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt
CFLAGS = -Wall -Wextra -Werror
DEBUG = -fsanitize=address -g
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
SRCS_DIR = srcs
OBJS_DIR = objs
SRCS =	render_scene.c \
	canvas_functions.c \
	tuple_functions.c \
	matrix_functions.c \
	rays.c \
	intersections.c \
	light.c
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: ${NAME} ${LIBFT}

debug: CFLAGS += ${DEBUG}
debug: re

${LIBFT}:
	@make -s -C ${LIBFT_DIR}
	@echo "compiling libft"

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@ -lm

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	gcc $(CFLAGS) -c $< -o $@

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

clean:
	@make -s -C ${LIBFT_DIR} clean
	@echo "make clean libft"
	rm -rf ${OBJS_DIR}

fclean: clean
	@make -s -C ${LIBFT_DIR} fclean
	@echo "make fclean libft"
	rm -f ${NAME}

re: fclean all
	@make -s -C ${LIBFT_DIR} re

.PHONY: all clean fclean re