NAME = PmergeMe

SRCS = main.cpp PmergeMe.cpp

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

OBJDIR = objs
DEPDIR = deps

OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))
DEPS = $(patsubst %.cpp,$(DEPDIR)/%.d,$(SRCS))

all: directories $(NAME)

$(OBJDIR)/%.o: %.cpp
	$(FLAGS) -MMD -MP -MF $(patsubst $(OBJDIR)/%.o,$(DEPDIR)/%.d,$@) -I ./ -c $< -o $@

$(NAME): $(OBJS)
	$(FLAGS) $(OBJS) -o $(NAME)

run: all
	./$(NAME) `shuf -i 1-100000 -n 3000 | tr "\n" " "`

directories: 
	@mkdir -p $(OBJDIR)
	@mkdir -p $(DEPDIR)

clean:
	rm -f $(OBJS) $(DEPS)
	rm -rf $(OBJDIR) $(DEPDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: clean all fclean re directories run
