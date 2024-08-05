NAME = Zombie

FLAGS = c++ -std=c++98 -Wall -Wextra -Werror

SRCS = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

OBJDIR = objs
DEPDIR = deps

OBJS = $(patsubst %.cpp,$(OBJDIR)/%.o,$(SRCS))
DEPS = $(patsubst %.cpp,$(DEPDIR)/%.d,$(SRCS))

all: directories $(NAME)

$(OBJDIR)/%.o: %.cpp
	$(FLAGS) -MMD -MP -MF $(DEPDIR)/$*.d -I ./ -c $< -o $@

$(NAME): $(OBJS)
	$(FLAGS) $(OBJS) -o $(NAME)

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

.PHONY: clean all fclean re directories
