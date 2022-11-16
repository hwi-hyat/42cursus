# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: siykim <siykim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/06 15:29:29 by jeounpar          #+#    #+#              #
#    Updated: 2022/11/11 15:44:53 by siykim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		=	./src/00_A_parser.c \
				./src/00_B_array_validation.c \
				./src/01_A_solve.c \
				./src/01_B_random_case.c \
				./src/01_C_three_random_case.c \
				./src/01_D_five_random_case.c \
				./src/01_E_quick_sort.c \
				./src/03_opertaion_with_output.c \
				./src/03_push_operation.c \
				./src/03_reverse_rotate_opertaion.c \
				./src/03_rotate_opertaion.c \
				./src/03_swap_operation.c \
				./src/99_errors.c \
				./src/99_ft_atoi.c \
				./src/99_ft_split.c \
				./src/main.c

OBJECTS		=	$(SRCS:.c=.o)

all			: $(NAME)

$(NAME)		: $(OBJECTS)
		$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

clean		:
		rm -f $(OBJECTS)

fclean		: clean
		rm -f $(NAME)

re			: fclean all