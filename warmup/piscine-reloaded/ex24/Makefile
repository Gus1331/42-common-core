# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gustaoli <gustaoli@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 14:15:51 by gustaoli          #+#    #+#              #
#    Updated: 2025/07/17 18:33:26 by gustaoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

INCLUDES = -I includes

SRC = srcs/ft_putchar.c \
	srcs/ft_putstr.c \
	srcs/ft_strcmp.c \
	srcs/ft_strlen.c \
	srcs/ft_swap.c

OBJ = $(SRC:.c=.o)

NAME = libft.a

$(NAME): $(OBJ)
	ar rcs $@ $(OBJ)

%.o: %.c
	$(CC) $(INCLUDES) -c $< -o $@ $(FLAGS)

all: $(NAME)

clean: $(OBJ)
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
