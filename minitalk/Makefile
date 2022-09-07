
NAME		=	minitalk

SERVER		=	server

CLIENT		=	client

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

SERVER_SRCS	=	server.c	\
				ft_printf/ft_printf.c \
				ft_printf/types/type_di.c \
				ft_printf/types/type_s.c

CLINET_SRCS	=	client.c

SERVER_OBJS	=	server.o	\
				ft_printf/ft_printf.o \
				ft_printf/types/type_di.o \
				ft_printf/types/type_s.o

CLIENT_OBJS	=	client.o

$(NAME)		:	$(SERVER) $(CLIENT)

$(SERVER)	:	$(SERVER_OBJS)
	$(CC) $(SERVER_OBJS) -o $(SERVER)

$(CLIENT)	:	$(CLIENT_OBJS)
	$(CC) $(CLIENT_OBJS) -o $(CLIENT)

all:	$(NAME)

clean:
	rm -rf $(SERVER_OBJS) $(CLIENT_OBJS)

fclean: clean
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

re:
	make fclean
	make all

.PHONY: all clean fclean re