CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I./libft -I include
LDFLAGS = -L./libft -lft

NAME = pipex
MAIN = src/pipex.c

SRC = src/bin_paths.c \
	src/execute_cmd.c \
	src/format_args.c \
	src/here_doc_bonus.c

OBJ = $(SRC:.c=.o) $(MAIN:.c=.o)

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
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@echo "🧹 Arquivos .o limpos"

fclean: clean
	@make -C libft fclean --no-print-directory
	@rm -f $(NAME)
	@rm -f checker
	@echo "🧹 checker limpo"
	@echo "🧹 $(NAME) limpo\n"

re: fclean all

.PHONY: all re fclean clean 
