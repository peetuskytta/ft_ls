CC := gcc
DEBUG_F := -g
FLAGS := -Wall -Wextra -Werror

NAME := ft_ls
SOURCES := start.c prints.c parser.c

OBJ := $(SOURCES:.c=.o)

LIBFT_M := make -C libft

all: $(NAME)

$(NAME):
	$(LIBFT_M)
	@$(CC) $(FLAGS) -c $(SOURCES)
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all

debug:
	@$(LIBFT_M)
	@$(CC) $(FLAGS) $(DEBUG_F) -c $(SOURCES)
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

.PHONY: make all debug re clean fclean