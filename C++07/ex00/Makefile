NAME =		template
SOURCES =	main.cpp 

OBJDIR = build
OBJECTS = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))
DEP = $(OBJECTS:%.o=%.d)
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -MMD -std=c++98
RM = rm

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXFLAGS) -o $(NAME)

$(OBJDIR)/%.o:%.cpp
	@mkdir -p $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

-include $(DEP)

clean:
	@$(RM) -rf $(OBJDIR)

fclean: clean
	@$(RM) -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re