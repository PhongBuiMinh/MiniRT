# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbui-min <fbui-min@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 16:14:51 by fbui-min          #+#    #+#              #
#    Updated: 2026/07/07 14:04:19 by fbui-min         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN   = \033[0;32m
RED     = \033[0;31m
DEFAULT = \033[0m

NAME    = minirt
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

OS_TYPE := $(shell uname -s)

ifeq ($(OS_TYPE),Darwin)
	MLX_PATH = lib/minilibx-macos
	MLX_FLAG = -framework OpenGL -framework AppKit
else ifeq ($(OS_TYPE),Linux)
	MLX_PATH = lib/minilibx-linux
	MLX_FLAG = -lXext -lX11 -lm -lz
endif

LIBFT_PATH = lib/libft
LIBFT      = $(LIBFT_PATH)/libft.a
MLX        = $(MLX_PATH)/libmlx.a

SRC_DIR = srcs
SRC     = main.c \
		  hook_handler.c \
		  init.c \
		  parse_elements.c parse_helpers.c parse_objects.c parser.c \
		  build_world.c

OBJ_DIR = obj
OBJ     = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(LIBFT):
	@echo "$(GREEN)Building libft library...$(DEFAULT)"
	@$(MAKE) -C $(LIBFT_PATH)

$(MLX):
	@echo "$(GREEN)Building mlx library...$(DEFAULT)"
	@$(MAKE) -C $(MLX_PATH)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(GREEN)Compiling source file...$(DEFAULT)"
	@$(CC) $(CFLAGS) -Iincludes -I$(LIBFT_PATH) -I$(MLX_PATH) -c $< -o $@

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	@echo "$(GREEN)Linking files...$(DEFAULT)"
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx $(MLX_FLAG) -o $(NAME)

clean:
	@echo "$(RED)Removing object files...$(DEFAULT)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C $(LIBFT_PATH)
	@if [ -d "$(MLX_PATH)" ]; then $(MAKE) clean -C $(MLX_PATH); fi

fclean: clean
	@echo "$(RED)Removing program...$(DEFAULT)"
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re