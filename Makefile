# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfiqar <hfiqar@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 10:52:05 by hfiqar            #+#    #+#              #
#    Updated: 2024/05/17 20:44:23 by hfiqar           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

FILES = check_c \
check_valid_map \
drawing_map \
freed \
ft_putchar_fd \
get_next_line \
get_next_line_utils \
hooks \
main \
map_copy \
parse_utils \
assist_hooks

SRC = $(FILES:=.c)

OBJ = $(SRC:.c=.o)

HEADER = so_long.h
HEADER_G = get_next_line.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -Imlx

all : $(NAME)

$(NAME) : $(OBJ) 
	@$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@printf "[completed :)]" $@
	
%.o : %.c $(HEADER) $(HEADER_G)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\e[0;32m%s .....\r\e[0;32m" $@
clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all


.PHONY : all clean fclean re
