CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I libft.h
NAME = libft.a
OBJ = $(SRC:.c=.o)
SRC = \
	ft_strlen.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_strlcpy.c \
	ft_isascii.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_atoi.c 

$(NAME) : $(OBJ)
	@ar rcs $@ $(OBJ)

%.o : %.c
	@$(CC) $(INCLUDE) $(FLAGS) -c $^ -o $@
	@echo "$@ ✅"

all : $(NAME)

clean:
	@rm -rf $(OBJ)
	@echo "🧹 Arquivos .o limpos"

fclean: clean
	@rm -f $(NAME)
	@echo "🧹 $(NAME) limpo\n"

re: fclean all

# Para testes manuais

main: re
	@$(CC) $(INCLUDE) $(FLAGS) -c main.c -o main.o
	@$(CC) main.o $(FLAGS) -L. -lft -o main
	@echo "\nMain gerado com sucesso"
	@echo "\nnorminette"
	@norminette $(SRC) -R CheckForbiddenSourceHeader
	@rm -rf *.o
	@echo "\nSem erros de norminette ✅"
