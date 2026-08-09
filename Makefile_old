# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/05 21:36:59 by bpetrovi          #+#    #+#              #
#    Updated: 2026/07/10 20:14:24 by bpetrovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt
INCLUDES = -Iincludes -Ilibft
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)
DEBUG = -g
LIBFT_DIR = libft
LIBFT = ${LIBFT_DIR}/libft.a
SRCS_DIR = src
OBJS_DIR = build
CORE_SRCS = canvas.c \
			color.c \
			normal_at.c \
			hit.c \
			intersect.c \
			intersect_manipulation.c \
            intersect_helper.c \
            tuples.c \
            matrices.c \
            rays.c \
            objects.c \
            light.c \
			helper_math.c \
			geometry.c \
			transformations.c \
			render.c \
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