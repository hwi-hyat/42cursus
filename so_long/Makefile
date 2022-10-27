# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 01:04:10 by siykim            #+#    #+#              #
#    Updated: 2022/10/27 14:29:51 by siykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

BONUS		= 	so_long_bonus

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
	$(CC) $(CFLAGS) -L./mlx -lmlx -framework OpenGL -framework AppKit $^ -o $(NAME)

$(BONUS)	:	$(BONUS_OBJS)
	$(CC) $(CFLAGS) -L./mlx -lmlx -framework OpenGL -framework AppKit $^ -o $(BONUS)
	
all		:	$(NAME)

bonus	:	$(BONUS)

clean	:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean	: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)
re:
	make fclean
	make all

.PHONY: all clean fclean re bonus