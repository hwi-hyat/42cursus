SRCS		=	$(wildcard *.c) 
BNS_SRCS	=	
OBJS		=	${SRCS:.c=.o}
BNS_OBJS	=	${BNS_SRCS:.c=.o}
NAME		=	libft.a
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar -rcs ${NAME} ${OBJS}

all: ${NAME}

bonus: ${OBJS} ${BNS_OBJS}
	ar -rc ${NAME} ${OBJS}
	ranlib ${NAME}
clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re