NAME	= map
SRCS	= main.cpp\
		Contact.cpp\
		PhoneBook.cpp
OBJS	= $(SRCS:.c=.o)
CC		= c++
RM		= rm -f
CFLAGS	= -Wall -Werror -Wextra -std=c++98

%.o:			%.c
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $^ -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re: 			
				make fclean
				make all

.PHONY: 		all, clean, fclean, re