NAME = a.out
FLAGS = -Wall -Wextra -Werror -std=c++98 -I $(INC) -g3

CC = c++

INC = ./headers/

SRCS = srcs/main.cpp \

$(NAME) : $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

all : $(NAME)

clean :
	rm -f *.o */*.o

fclean : clean
	rm -f $(NAME)
	rm -f *_shrubbery
re : fclean all

.PHONY : clean fclean all re
