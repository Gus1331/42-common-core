CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I./libft -I./include
LDFLAGS = -L./libft -lft
NAME = libftprintf.a
SRC = src/ft_printf.c src/ft_printfchar.c src/ft_printf_string.c src/ft_printfnumbers.c src/ft_printf_hex.c
OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	@make -C libft --no-print-directory
	@echo "lib compilada ✅"
	@cp libft/libft.a .
	@mv libft.a $@
	@ar rcs $@ $(OBJ)

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
	@$(CC) $(INCLUDE) $(FLAGS) -c main.c -o main.o
	@$(CC) main.o $(FLAGS) -L. -lft_printf -o main
	@echo "\nMain gerado com sucesso"
	@echo "\nnorminette"
	@norminette $(SRC) -R CheckForbiddenSourceHeader
	@echo "\nSem erros de norminette ✅"
	@rm -rf *.o

.PHONY: all re fclean clean 
