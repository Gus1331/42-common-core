# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 12:30:20 by gustaoli          #+#    #+#              #
#    Updated: 2025/07/18 13:53:28 by gustaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes

NAME = ft_display_file

SRC = srcs/main.c \
	srcs/display.c

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) -o $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(INCLUDES) $(FLAGS) -c $^ -o $@

all : $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
