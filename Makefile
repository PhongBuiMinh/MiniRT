# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/05 21:36:59 by bpetrovi          #+#    #+#              #
#    Updated: 2026/06/09 20:50:57 by bpetrovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt
INCLUDES = -Iincludes -Ilibft
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
DEBUG = -fsanitize=address -g
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
SRCS_DIR = src
OBJS_DIR = build
CORE_SRCS = canvas_functions.c \
            tuples.c \
            matrices.c \
            rays.c \
            objects.c \
            intersections.c \
            light.c \
			helper_math.c \
			geometry.c \
			transformations.c \
			world.c
SRCS = main.c $(CORE_SRCS)
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: ${NAME} ${LIBFT}

debug: CFLAGS += ${DEBUG}
debug: re

test: ${LIBFT}
	@$(MAKE) SRCS="$(CORE_SRCS) tests/lightning_tests.c tests/matrix_tests.c tests/tests_runner.c" NAME="test_runner" all

${LIBFT}:
	@make -s -C ${LIBFT_DIR}
	@echo "compiling libft"

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME) -lm

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

$(OBJS_DIR)/tests/%.o: tests/%.c | $(OBJS_DIR)/tests
	@mkdir -p $(dir $@)
	gcc $(CFLAGS) -c $< -o $@

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${OBJS_DIR}/tests:
	mkdir -p ${OBJS_DIR}/tests

clean:
	@make -s -C ${LIBFT_DIR} clean
	@echo "make clean libft"
	rm -rf ${OBJS_DIR}

fclean: clean
	@make -s -C ${LIBFT_DIR} fclean
	@echo "make fclean libft"
	rm -f minirt test_runner

re: fclean all
	@make -s -C ${LIBFT_DIR} re

.PHONY: all clean fclean re debug test