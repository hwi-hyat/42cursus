NAME	= ex03
SRCS	= main.cpp\
		MateriaSource.cpp\
		AMateria.cpp\
		Character.cpp\
		Cure.cpp\
		Ice.cpp
		
OBJS	= $(SRCS:.cpp=.o)
CPP		= c++
RM		= rm -f
CPPFLAGS	= -Wall -Werror -Wextra -std=c++98

%.o:			%.c
				$(CPP) $(CPPFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CPP) $(CPPFLAGS) $^ -o $@

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re: 			
				make fclean
				make all

.PHONY: 		all, clean, fclean, re