CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I libft.h
NAME = libft.a
OBJ = $(SRC:.c=.o)
SRC = \
	ft_strlen.c \
	ft_isalpha.c \
	ft_atoi.c 

$(NAME) : $(OBJ)
	ar rcs $@ $(OBJ)

%.o : %.c
	$(CC) $(INCLUDE) $(FLAGS) -c $^ -o $@

all : $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

# Para testes manuais

main: re
	$(CC) $(INCLUDE) $(FLAGS) -c main.c -o main.o
	$(CC) main.o $(FLAGS) -L. -lft -o main
	norminette $(SRC) -R CheckForbiddenSourceHeader
	rm -rf *.o
