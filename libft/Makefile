NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =	$(wildcard *.c) 

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)
$(NAME) : $(OBJECTS)
	$(CC)	$(CFLAGS)	-o	$(NAME)	$(OBJECTS)

clean:
	rm	-f	$(OBJECTS)

fclean: clean
	rm	-f	$(NAME)
	
re: fclean all