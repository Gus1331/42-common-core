CC = cc
FLAGS = -Wall -Wextra -Werror --save-temps
INCLUDE = -I libft.h
NAME = libft.a
OBJ = $(SRC:.c=.o)
OBJBONUS = $(OBJ) $(SCRBONUS:.c=.o)
SRC = \
	ft_strlen.c \
	ft_isalpha.c \
	ft_isalnum.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_strlcpy.c \
	ft_isascii.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_bzero.c \
	ft_strnstr.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_atoi.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

SCRBONUS= \
	ft_lstnew_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

$(NAME) : $(OBJ)
	@ar rcs $@ $(OBJ)

%.o : %.c
	@$(CC) $(INCLUDE) $(FLAGS) -c $^ -o $@
	@echo "$@ ✅"

all : $(NAME)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(OBJBONUS)
	@echo "🧹 Arquivos .o limpos"

fclean: clean
	@rm -f $(NAME)
	@echo "🧹 $(NAME) limpo\n"

re: fclean all

bonus: $(OBJBONUS)
	@ar rcs $(NAME) $(OBJBONUS)

# Para testes manuais

main: re
	@$(CC) $(INCLUDE) $(FLAGS) -c main.c -o main.o
	@$(CC) main.o $(FLAGS) -L. -lft -o main
	@echo "\nMain gerado com sucesso"
	@echo "\nnorminette"
	@norminette $(SRC) -R CheckForbiddenSourceHeader
	@echo "\nSem erros de norminette ✅"
	@rm -rf *.o
