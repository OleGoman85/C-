# Name of the executable file
NAME = fixed

# Automatically find all .cpp files in the current directory
SRCS = $(wildcard *.cpp)

# Compiler and compilation flags
CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++11

# Default main target
all: $(NAME)

# Rule to create the executable file from all .cpp files
$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@./fixed
	@rm -f $(NAME)

# Declare targets as phony
.PHONY: all #clean fclean re