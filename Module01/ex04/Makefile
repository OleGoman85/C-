# Name of the executable file
NAME = replace

# Automatically find all .cpp files in the current directory
SRCS = $(wildcard *.cpp)

# Compiler and compilation flags
CC = clang++
CFLAGS = -Wall -Wextra -Werror -std=c++11

# Default main target
all: $(NAME)

# Rule to create the executable file from all .cpp files
$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	
# Clean target: does nothing since object files are not created
clean:
	@echo "Nothing to clean"

# Fclean target: removes only the executable file
fclean: clean
	@rm -f $(NAME)

# Re target: complete rebuild of the project
re: fclean all

# Declare targets as phony
.PHONY: all clean fclean re

