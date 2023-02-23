NAME	= 03exe
SRCS	= main.cpp\
		HumanA.cpp\
		HumanB.cpp\
		Weapon.cpp
OBJS	= $(SRCS:.cpp=.o)
CC		= c++
RM		= rm -f
FLAGS	= -Wall -Werror -Wextra -std=c++98

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(FLAGS) $^ -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re: 			
				make fclean
				make all

.PHONY: 		all, clean, fclean, re