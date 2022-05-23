CC := gcc
DEBUG_F := -g
FLAGS := -Wall -Wextra -Werror

NAME := ft_ls
SOURCES := ls_main.c \
	ls_error_handling.c \
	ls_primary_checks.c \
	ls_prints_1.c \
	ls_prints_2.c \
	ls_sort.c \
	ls_no_flags.c \
	ls_with_flags.c \
	ls_utility_functions_1.c \
	ls_utility_functions_2.c \

OBJ := $(SOURCES:.c=.o)

LIBFT_M := make -s -C libft

all: $(NAME)

$(NAME):
	@$(LIBFT_M)
	@$(CC) $(FLAGS) -c $(SOURCES)
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean:
	@make -s -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -s -C libft fclean
	@rm -f $(NAME)

re: fclean all

debug:
	@$(LIBFT_M)
	@$(CC) $(FLAGS) $(DEBUG_F) -c $(SOURCES)
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)

.PHONY: make all debug re clean fclean
