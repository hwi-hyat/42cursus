# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 01:34:26 by siykim            #+#    #+#              #
#    Updated: 2022/07/28 22:41:19 by siykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_SRCS	=	server.c \
				ft_printf/ft_printf.c \
				ft_printf/types/type_di.c \
				ft_printf/types/type_s.c

CLIENT_SRCS	=	client.c \
				ft_printf/ft_printf.c \
				ft_printf/types/type_di.c \
				ft_printf/types/type_s.c

SERVER_OBJS	=	${SERVER_SRCS:.c=.o}

CLIENT_OBJS	=	${CLIENT_SRCS:.c=.o}

SERVER_NAME	=	server

CLIENT_NAME	=	client

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

${SERVER_NAME}: ${SERVER_OBJS}
	ar -rc ${SERVER_NAME} ${SERVER_OBJS}
	ranlib ${SERVER_NAME}

${CLIENT_NAME}: ${CLIENT_OBJS}
	ar -rc ${CLIENT_NAME} ${CLIENT_OBJS}
	ranlib ${CLIENT_NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
	
all: 
	${SERVER_NAME}
	${CLIENT_NAME}

server:
	${SERVER_NAME}
	
client:
	${CLIENT_NAME}

clean:
	rm -f ${SERVER_OBJS}
	rm -f ${CLIENT_OBJS}

fclean: clean
	rm -f ${SERVER_NAME}
	rm -f ${CLIENT_NAME}

re: 
	make fclean
	make all

.PHONY: all clean fclean re server client