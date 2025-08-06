CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I./libft 
LDFLAGS = -L./libft -lft
NAME = ft_printf
SRC = ft_printf.c ft_printfchar.c ft_printf_string.c ft_printfnumbers.c ft_printf_hex.c
OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	@make -C libft --no-print-directory
	@echo "lib compilada ✅"
	@$(CC) $(FLAGS) -o $@ $(OBJ) $(LDFLAGS)

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

# Para testes manuais

main: re
	@echo "\nnorminette"
	@norminette $(SRC) -R CheckForbiddenSourceHeader
	@echo "\nSem erros de norminette ✅"
	@rm -rf *.o
