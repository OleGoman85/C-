# NAME = iter_test

# SRCS = $(wildcard *.cpp)

# CC = c++
# CFLAGS = -Wall -Wextra -Werror

# all: $(NAME)

# $(NAME): $(SRCS)
# 	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

# clean:
# 	@echo "Nothing to clean"

# fclean: clean
# 	@rm -f $(NAME)

# re: fclean all

# .PHONY: all  clean fclean re


NAME = iter_test

SRCS = $(wildcard *.cpp)

CC = c++
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@./iter_test
	@rm -f $(NAME)