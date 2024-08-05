NAME = PhoneBook

FLAGS = c++ -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp phonebook.cpp utils.cpp

INCLUDE = phonebook.hpp contact.hpp

OBJS = $(SRCS:.cpp=.o)

DEPS = $(SRCS:.cpp=.d)

all : $(NAME)

%.o:%.cpp Makefile
	$(FLAGS) -MMD -I ./ -c $< -o $@

$(NAME): $(OBJS) 
	$(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY : clean all fclean re
