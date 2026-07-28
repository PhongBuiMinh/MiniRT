# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbui-min <fbui-min@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/01 16:14:51 by fbui-min          #+#    #+#              #
#    Updated: 2026/07/28 21:57:58 by fbui-min         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN   = \033[0;32m
RED     = \033[0;31m
DEFAULT = \033[0m

NAME    = minirt
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g

OS_TYPE := $(shell uname -s)

LIBFT_PATH = lib/libft
LIBFT      = $(LIBFT_PATH)/libft.a

MLX42_PATH = lib/MLX42
MLX42_LIB  = $(MLX42_PATH)/build/libmlx42.a

ifeq ($(OS_TYPE),Darwin)
	MLX42_FLAG = -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else ifeq ($(OS_TYPE),Linux)
	MLX42_FLAG = -ldl -lglfw -pthread -lm
endif

SRC_DIR = srcs
SRC     = main.c \
		  hook_handler.c \
		  render_init.c render_draw.c \
		  parse_elements.c parse_helpers.c parse_helpers2.c parse_objects.c parser.c \
		  build_world.c

OBJ_DIR = obj
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