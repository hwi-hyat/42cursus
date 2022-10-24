# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 01:04:10 by siykim            #+#    #+#              #
#    Updated: 2022/10/25 01:06:37 by siykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS	=	so_long.c\
			libft_so_long.c\
			00_util.c\
			01_parse_map.c\


OBJS	=	

$(NAME)	:	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all:	$(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
re:
	make fclean
	make all

.PHONY: all clean fclean re