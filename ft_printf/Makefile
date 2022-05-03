# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 01:34:26 by siykim            #+#    #+#              #
#    Updated: 2022/05/02 20:33:33 by siykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	

BNS_SRCS	=	

OBJS		=	${SRCS:.c=.o}

BNS_OBJS	=	${BNS_SRCS:.c=.o}

NAME		=	libftprintf.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

ifdef IS_BNS
	ALL_OBJS = ${OBJS} ${BNS_OBJS}
else
	ALL_OBJS = ${OBJS}
endif

${NAME}: ${ALL_OBJS}
	ar -rc ${NAME} ${ALL_OBJS}
	ranlib ${NAME}

all: ${NAME}

bonus:
	make IS_BNS=1 all

clean:
	rm -f ${OBJS} ${BNS_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus