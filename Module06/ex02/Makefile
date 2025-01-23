NAME = identify_real_type

SRCS = $(wildcard *.cpp)

CC = c++
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)
	@./identify_real_type
	@rm -f $(NAME)

.PHONY: all  #clean fclean re