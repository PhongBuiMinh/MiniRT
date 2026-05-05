# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/05 21:36:59 by bpetrovi          #+#    #+#              #
#    Updated: 2026/05/05 22:11:46 by bpetrovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
OBJS_DIR = objs
SRCS =	main.c \
	canvas_functions.c \
	tuple_functions.c 
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: ${NAME}

${NAME}: ${OBJS}
	gcc $(CFLAGS) $^ -o $@ -lm

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	gcc $(CFLAGS) -c $< -o $@

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

clean:
	rm -rf ${OBJS_DIR}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re