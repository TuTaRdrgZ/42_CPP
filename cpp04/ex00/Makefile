NAME = Animal

SRCS = main.cpp Dog.cpp Cat.cpp Animal.cpp WrongAnimal.cpp WrongCat.cpp

INCLUDES = Dog.hpp Cat.hpp Animal.hpp WrongCat.hpp WrongAnimal.hpp

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

OBJS = $(SRCS:.cpp=.o)

all = $(NAME)

$(NAME): $(INCLUDES) $(OBJS) Makefile
	$(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean all fclean re
