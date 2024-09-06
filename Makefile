# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apodader <apodader@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/11 14:45:09 by apodader          #+#    #+#              #
#    Updated: 2024/09/06 20:23:56 by apodader         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

OS := $(shell uname)

CC = cc
RM = rm -rf

FLAGS = -Wall -Wextra -Werror -Iincludes -MMD

ifeq ($(OS), Linux)
    MLX_FLAGS := -Lmlx -lmlx -lX11 -lXext -lXrender -lXrandr -lXfixes -lXcursor -lm
else ifeq ($(OS), Darwin)
    MLX_FLAGS := -Lmlx -lmlx -framework OpenGL -framework AppKit
endif

SRC = draw gameplay init player_movement valid_map exit_game get_next_line main printf ft_split \
	get_next_line_utils map_checker utils
INC = $(NAME) get_next_line 

DIR_SRC = ./src/
INCDIR = ./includes/
DIR_OBJ_DST = ./obj/

SRCS := $(addprefix $(DIR_SRC),$(addsuffix .c,$(SRC)))
OBJS := $(addprefix $(DIR_OBJ_DST),$(addsuffix .o,$(SRC)))
DSTS := $(addprefix $(DIR_OBJ_DST),$(addsuffix .d,$(SRC)))
INCLUDE := $(addprefix $(INCDIR),$(addsuffix .h, $(INC)))

-include $(DSTS)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C ./mlx
	$(CC) $(FLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(DIR_OBJ_DST)%.o: $(DIR_SRC)%.c
	@mkdir -p $(DIR_OBJ_DST)
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(DIR_OBJ_DST)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re