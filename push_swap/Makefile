CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I./libft -I include
LDFLAGS = -L./libft -lft
NAME = push_swap
MAIN = src/push_swap.c
MAIN_BONUS = bonus/checker_bonus.c
SRC = src/validate_args.c \
	src/manage_stack.c \
	src/operation_push.c \
	src/operation_rotate.c \
	src/operation_rrotate.c \
	src/operation_swap.c \
	src/sort.c \
	src/sort_low.c \
	src/search_stack.c \
	src/align_stack.c \
	src/cheapest_utils.c

SRC_BONUS = bonus/operation_push_bonus.c \
	bonus/operation_rotate_bonus.c \
	bonus/operation_rrotate_bonus.c \
	bonus/operation_swap_bonus.c

OBJ = $(SRC:.c=.o) $(MAIN:.c=.o)
OBJ_BONUS = $(SRC:.c=.o) $(SRC_BONUS:.c=.o) $(MAIN_BONUS:.c=.o)

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

bonus : $(OBJ_BONUS)
	@make -C libft --no-print-directory
	@echo "lib compilada ✅"
	@$(CC) $(OBJ_BONUS) $(FLAGS) $(LDFLAGS) -o checker
	@echo "Checker gerado com sucesso ✅✅✅"

.PHONY: all re fclean clean 
