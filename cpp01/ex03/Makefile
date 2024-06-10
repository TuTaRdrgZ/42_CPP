NAME = Violence

FLAGS = c++ -std=c++98 -Wall -Wextra -Werror

SRCS= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

INCLUDE = Weapon.hpp HumanA.hpp HumanB.hpp

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
		$(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean all fclean re
