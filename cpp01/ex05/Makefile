
NAME = Harl

SRCS = main.cpp Harl.cpp

INCLUDE = Harl.hpp

FLAGS = c++ -std=c++98 -Wall -Wextra -Werror

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJS) $(INCLUDE) Makefile
		$(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean all fclean re
