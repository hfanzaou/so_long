# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 14:29:12 by hfanzaou          #+#    #+#              #
#    Updated: 2022/06/28 14:29:15 by hfanzaou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRCS = so_long.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c srcs/checkmap.c \
	   srcs/key_hook.c srcs/move_player.c srcs/put_images.c srcs/to_map.c srcs/check_collections.c srcs/ft_free_exit.c \
	   srcs/loop_hooks.c srcs/ft_strchr.c srcs/ft_itoa.c srcs/ft_openexit.c srcs/ft_putnbr.c
SFLAGS = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -I /usr/locale/include
FLAGS = -Wall -Werror -Wextra
CC = gcc

all : $(NAME)

$(NAME)	: $(SRCS)
	$(CC) $(FLAGS) $(SFLAGS) $(SRCS) -D BUFFER_SIZE=1 -o $(NAME)

clean : 

fclean : clean
	rm -rf $(NAME)

re : fclean all