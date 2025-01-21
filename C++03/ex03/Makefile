NAME =		DiamondTrap
SOURCES =	main.cpp \
			ClapTrap.cpp \
			ScavTrap.cpp \
			FragTrap.cpp \
			DiamondTrap.cpp
			
OBJDIR = build
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))
DEP = $(OBJECTS:%.o=%.d)
CC = c++
CFLAGS = -Wall -Werror -Wextra -MMD -std=c++98
RM = rm

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(NAME)

$(OBJDIR)/%.o:%.cpp
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean:
	@$(RM) -rf $(OBJDIR)

fclean: clean
	@$(RM) -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re