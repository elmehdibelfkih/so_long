# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 10:59:06 by ebelfkih          #+#    #+#              #
#    Updated: 2023/01/27 23:13:51 by ebelfkih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -f

FILES = code/player_movement.c code/read_and_check_map.c code/so_long.c code/utils.c code/utils2.c code/graphic.c

all:
	$(CC) $(FILES) -o  $(NAME) $(FLAGS) $(MLX)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: mandatory re fclean all bonus maps images test