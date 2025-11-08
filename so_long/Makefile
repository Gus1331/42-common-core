CC = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = -I./libft -I include -I $(MLX_DIR)/include
LDFLAGS = -L./libft -lft

NAME = so_long
MAIN = src/so_long.c

MLX_DIR = MLX42
MLX = $(MLX_DIR)/build/libmlx42.a
LIBS = -L $(MLX_DIR)/build -lmlx42 -ldl -lglfw -pthread -lm

SRC = src/key_hook.c \
	src/errors.c \
	src/validate_map.c \
	src/validate_map_path.c \
	src/game.c \
	src/load_textures.c \
	src/load_map.c \
	src/load_images.c \
	src/player.c \
	src/scenes.c

OBJ = $(SRC:.c=.o) $(MAIN:.c=.o)

$(NAME) : $(OBJ)
	@make -C libft --no-print-directory
	@echo "lib compilada ✅"
	@cmake -S $(MLX_DIR) -B $(MLX_DIR)/build > /dev/null
	@cmake --build $(MLX_DIR)/build -j4 > /dev/null
	@$(CC) $(OBJ) $(FLAGS) $(LDFLAGS) $(LIBS) -o $@
	@echo "\n$@ gerado com sucesso ✅✅✅"

%.o : %.c
	@$(CC) $(INCLUDE) $(FLAGS) -c $< -o $@
	@echo "$@ compilado ✅"

all : $(NAME)

clean:
	@make -C libft clean --no-print-directory
	@rm -rf $(OBJ) $(OBJ_BONUS)
	@echo "🧹 Arquivos .o limpos\n"

fclean: clean
	@make -C libft fclean --no-print-directory
	@rm -rf $(MLX42)/build
	@echo "🧹 $(MLX42) limpo"
	@rm -f $(NAME)
	@echo "🧹 $(NAME) limpo\n"

re: fclean all

game: all
	./$(NAME) maps/map1.ber
	./$(NAME) maps/map2.ber
	./$(NAME) maps/map3.ber
	./$(NAME) maps/map4.ber

.PHONY: all re fclean clean 
