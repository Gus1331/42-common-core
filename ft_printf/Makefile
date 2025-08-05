CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I./libft 
LDFLAGS = -L./libft -lft
NAME = ft_printf
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	@make -C libft
	$(CC) $(FLAGS) -o $@ $(OBJ) $(LDFLAGS)

%.o : %.c
	@$(CC) $(INCLUDE) $(FLAGS) -c $< -o $@
	@echo "$@ compilado - ✅"

all : $(NAME)

clean:
	@make -C /libft clean
	@rm -rf $(OBJ)
	@echo "🧹 Arquivos .o limpos"

fclean: clean
	@make -C /libft fclean
	@rm -f $(NAME)
	@echo "🧹 $(NAME) limpo\n"

re: fclean all

# Para testes manuais

main: re
	@echo "\nnorminette"
	@norminette $(SRC) -R CheckForbiddenSourceHeader
	@echo "\nSem erros de norminette ✅"
	@rm -rf *.o
