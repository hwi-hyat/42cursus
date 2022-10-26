# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 01:04:10 by siykim            #+#    #+#              #
#    Updated: 2022/10/26 17:47:01 by siykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	so_long.c\
				libft_so_long.c\
				00_util.c\
				01_parse_map.c\
				01_parse_map_2.c\
				02_input.c\
				02_move.c\
				03_set_image.c

BONUS_SRCS	=	so_long.c\
				libft_so_long.c\
				00_util.c\
				01_parse_map.c\
				01_parse_map_2.c\
				02_input_bonus.c\
				02_move.c\
				03_set_image_bonus.c

OBJS		=	so_long.o\
				libft_so_long.o\
				00_util.o\
				01_parse_map.o\
				01_parse_map_2.o\
				02_input.o\
				02_move.o\
				03_set_image.o

BONUS_OBJS	=	so_long.o\
				libft_so_long.o\
				00_util.o\
				01_parse_map.o\
				01_parse_map_2.o\
				02_input_bonus.o\
				02_move.o\
				03_set_image_bonus.o

$(NAME)	:	$(OBJS)
	$(CC) $(CFLAGS) -L./mlx -lmlx -framework OpenGL -framework AppKit $^ -o so_long

bonus	:	$(BONUS_OBJS)
	$(CC) $(CFLAGS) -L./mlx -lmlx -framework OpenGL -framework AppKit $^ -o so_long_bonus
	
all		:	$(NAME)

clean	:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean	: clean
	rm -rf $(NAME)
re:
	make fclean
	make all

.PHONY: all clean fclean re bonus