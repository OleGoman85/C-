NAME = phonebook

BRed = \033[1;31m
BGreen = \033[1;32m

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++11

SRCS = $(wildcard *.cpp)

RM = rm -f

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
	@echo "$(BGreen)READY!"

clean:
	@$(RM) $(NAME)
	@echo "$(BRed)CLEAN!"

fclean:
	@$(RM) $(NAME)
	@echo "$(BRed)CLEAN!"

re: fclean all