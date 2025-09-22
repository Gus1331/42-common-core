CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I./libft -I include
LDFLAGS = -L./libft -lft
NAME = push_swap
SRC = src/push_swap.c \
	src/validate_args.c \
	src/manage_stack.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	@make -C libft --no-print-directory
	@echo "lib compilada ✅"
	@$(CC) $(OBJ) $(FLAGS) $(LDFLAGS) -o $@
	@echo "\n$@ gerado com sucesso ✅✅✅"

%.o : %.c
	@$(CC) $(INCLUDE) $(FLAGS) -c $< -o $@
	@echo "$@ compilado ✅"

all : $(NAME)

clean:
	@make -C libft clean --no-print-directory
	@rm -rf $(OBJ)
	@echo "🧹 Arquivos .o limpos"

fclean: clean
	@make -C libft fclean --no-print-directory
	@rm -f $(NAME)
	@echo "🧹 $(NAME) limpo\n"

re: fclean all

.PHONY: all re fclean clean 
