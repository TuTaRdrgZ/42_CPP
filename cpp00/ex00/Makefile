NAME= megaphone

SRC= megaphone.cpp

CXX= clang++

FLAGS= -Wall -Wextra -Werror -std=c++98

SRCO= $(SRC:.cpp=.o)

%.o: %.cpp
	$(CXX) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(SRCO)
	$(CXX) $(FLAGS) $(SRCO) -o $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

phony: all clean fclean re
