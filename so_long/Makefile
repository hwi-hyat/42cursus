# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 01:04:10 by siykim            #+#    #+#              #
#    Updated: 2022/10/26 01:19:41 by siykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS	=	so_long.c\
			libft_so_long.c\
			libft_so_long_2.c\
			00_util.c\
			01_parse_map.c\
			01_parse_map_2.c\
			02_input.c\
			02_move.c

OBJS	=	so_long.o\
			libft_so_long.o\
			libft_so_long_2.o\
			00_util.o\
			01_parse_map.o\
			01_parse_map_2.o\
			02_input.o\
			02_move.o

$(NAME)	: $(OBJS)
	$(CC) -L./mlx -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

all:	$(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
re:
	make fclean
	make all

.PHONY: all clean fclean re