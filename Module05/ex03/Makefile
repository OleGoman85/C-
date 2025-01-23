# Name of the executable file
NAME = bureaucrat

# Automatically find all .cpp files in the current directory
SRCS = $(wildcard *.cpp)

# Compiler and compilation flags
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

# Default main target
all: $(NAME)

# Rule to create the executable file from all .cpp files
$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@./bureaucrat
	@rm -f $(NAME)

# Declare targets as phony
.PHONY: all #clean fclean re

# /////////

# NAME = test
# SRCS = *.cpp
# CC = c++
# # CXXFLAGS = -std=c++17

# all:
# 	$(CC) $(SRCS) -o $(NAME)
# 	./test
# # $(CC) $(CXXFLAGS) $(SRCS) -o $(NAME)
