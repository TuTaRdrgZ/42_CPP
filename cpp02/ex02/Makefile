NAME = Fixed

FLAGS = c++ -std=c++98 -Wall -Wextra -Werror

SRCS= main.cpp Fixed.cpp

INCLUDE = Fixed.hpp 

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
