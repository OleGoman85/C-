NAME = megaphone

FLAGS = c++ -Wall -Wextra -Werror -std=c++98

SRCS = megaphone.cpp

RM = rm -f

BGreen = \033[1;32m
BRed = \033[1;31m

all: $(NAME)

$(NAME): $(SRCS)
	@$(FLAGS) -o $(NAME) $(SRCS)
	@echo "$(BGreen)READY!"

clean:
	@$(RM)

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BRed)CLEAN!"

re: fclean all