# # Name of the executable file
# NAME = serialize

# # Automatically find all .cpp files in the current directory
# SRCS = $(wildcard *.cpp)

# # Compiler and compilation flags
# CC = c++
# CFLAGS = -Wall -Wextra -Werror

# # Colors for output
# GREEN = \033[0;32m
# RED = \033[0;31m
# RESET = \033[0m

# # Default main target
# all: $(NAME)

# # Rule to create the executable file from all .cpp files
# $(NAME): $(SRCS)
# 	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
# 	@echo "$(GREEN)Executable $(NAME) created successfully.$(RESET)"

# # Rule to clean object files and executables
# clean:
# 	@rm -f $(NAME)
# 	@echo "$(RED)Cleaned all generated files.$(RESET)"

# # Rule to clean everything, including the executable
# fclean: clean

# # Rule to recompile everything
# re: fclean all

# # Declare targets as phony
# .PHONY: all clean fclean re


NAME = serialize

SRCS = $(wildcard *.cpp)

CC = c++
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@./serialize
	@rm -f $(NAME)

.PHONY: all  #clean fclean re
