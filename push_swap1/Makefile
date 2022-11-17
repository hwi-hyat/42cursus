# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 01:34:26 by siykim            #+#    #+#              #
#    Updated: 2022/09/07 18:42:29 by siykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	push_swap.c				\
				utilities.c				\
				00_stack.c				\
				00_stack_ops1.c			\
				00_stack_ops2.c			\
				00_stack_ops_executor.c	\
				01_sort.c				

OBJS		=	${SRCS:.c=.o}

NAME		=	push_swap

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

#.c.o:
#	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: 
	make fclean
	make all

.PHONY: all clean fclean re