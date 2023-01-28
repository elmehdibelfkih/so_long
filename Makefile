# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebelfkih <ebelfkih@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 10:59:06 by ebelfkih          #+#    #+#              #
#    Updated: 2023/01/28 05:57:05 by ebelfkih         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
ONAME = so_long.a 
MAIN = code/so_long.c
CC = cc -Wall -Werror -Wextra
MLX = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
AR = ar rc
FILES = code/player_movement.c code/read_and_check_map.c code/utils.c code/utils2.c code/graphic.c
OBJ = $(FILES:.c=.o)

RED = \033[0;31m
GREEN = \033[0;32m
PURPLE = \033[0;35m


all : $(NAME)

$(NAME) : $(OBJ)
	@echo "${RED} Start compiling ${GREEN} so_long ..."
	@sleep 3
	@$(AR) $(ONAME) $^
	@$(CC) $(MAIN) $(ONAME) $(MLX) -o $@
	@echo "${GREEN} so_long ${PURPLE} programe has been Created "

%.o : %.c code/so_long.h
	@$(CC) -o $@ -c $<

clean :
	@$(RM) $(OBJ)
	@echo "${RED} archieve files are removed"

fclean: clean
	@$(RM) $(NAME) $(ONAME)
	@echo "${RED} executable file removed"

re: fclean all