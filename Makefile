# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpetrovi <bpetrovi@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 16:14:51 by fbui-min          #+#    #+#              #
#    Updated: 2026/08/23 16:11:40 by bpetrovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN   = \033[0;32m
RED     = \033[0;31m
DEFAULT = \033[0m

NAME    = miniRT
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

OS_TYPE := $(shell uname -s)

LIBFT_PATH = lib/libft
LIBFT      = $(LIBFT_PATH)/libft.a

MLX42_PATH = lib/MLX42
MLX42_LIB  = $(MLX42_PATH)/build/libmlx42.a

ifeq ($(OS_TYPE),Darwin)
	GLFW_PATH = $(shell brew --prefix glfw 2>/dev/null)
	MLX42_FLAG = -L$(GLFW_PATH)/lib -lglfw \
             -framework Cocoa -framework OpenGL -framework IOKit
else ifeq ($(OS_TYPE),Linux)
	MLX42_FLAG = -ldl -lglfw -pthread -lm
endif

SRC_DIR = srcs
SRC     = main.c \
		math/geometry.c \
		math/helper_math.c \
		math/matrices.c \
		math/tuples.c \
		math/tuple_operations.c \
		parser/parse_elements.c \
		parser/parse_helpers.c \
		parser/parse_helpers2.c \
		parser/parse_cylinder.c \
		parser/parse_plane.c \
		parser/parse_sphere.c \
		parser/parser.c \
		render/canvas.c \
		render/color.c \
		render/light.c \
		render/render.c \
		render/render_multithread.c \
		render/camera.c \
		tracing/hit.c \
		tracing/intersect_helper.c \
		tracing/intersect_manipulation.c \
		tracing/intersect.c \
		tracing/normal_at.c \
		tracing/rays.c \
		window/hook_handler.c \
		window/window_init.c \
		world/build_world.c \
		world/objects.c \
		world/transformations.c \
		world/world.c \
		world/rotations.c \
		world/matrix_operations.c \
		world/object_create.c \
		utils/cleanup.c \
		utils/fatal.c \
		utils/ft_atof.c \
		utils/ft_get_next_line.c \
		utils/num_utils.c

OBJ_DIR = objs
OBJ     = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(LIBFT):
	@echo "$(GREEN)Building libft...$(DEFAULT)"
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX42_LIB):
	@echo "$(GREEN)Building MLX42...$(DEFAULT)"
	@cmake -S $(MLX42_PATH) -B $(MLX42_PATH)/build
	@cmake --build $(MLX42_PATH)/build -j4

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(dir $@)
	@echo "$(GREEN)Compiling $<...$(DEFAULT)"
	@$(CC) $(CFLAGS) -Iincludes -I$(LIBFT_PATH) -I$(MLX42_PATH)/include -c $< -o $@

$(NAME): $(LIBFT) $(MLX42_LIB) $(OBJ)
	@echo "$(GREEN)Linking $(NAME)...$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX42_LIB) $(MLX42_FLAG) -o $(NAME)

clean:
	@echo "$(RED)Removing object files...$(DEFAULT)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_PATH)
	@if [ -d "$(MLX42_PATH)/build" ]; then rm -rf $(MLX42_PATH)/build; fi

fclean: clean
	@echo "$(RED)Removing program...$(DEFAULT)"
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re

# git clone https://github.com/codam-coding-college/MLX42.git
# cd MLX42
# cmake -B build
# cmake --build build -j4