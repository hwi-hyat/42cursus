# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 01:34:26 by siykim            #+#    #+#              #
#    Updated: 2022/05/05 13:03:56 by siykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c	\
				types/type_c.c	\
				types/type_di.c	\
				types/type_p.c	\
				types/type_s.c	\
				types/type_u.c	\
				types/type_x.c	\
				types/type_XX.c	\

OBJS		=	${SRCS:.c=.o}

NAME		=	libftprintf.a

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

${NAME}: ${OBJS}
	ar -rc ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re