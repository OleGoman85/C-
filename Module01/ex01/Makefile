# Name of the executable file
NAME = zombie

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
	@./zombie
	@rm -f $(NAME)

# Declare targets as phony
.PHONY: all #clean fclean re
