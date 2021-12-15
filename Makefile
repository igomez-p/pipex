# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 20:15:03 by igomez-p          #+#    #+#              #
#    Updated: 2021/12/15 18:02:54 by igomez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC =	pipex.c \
		checker.c \
		libft/str_functions.c	\
		libft/ft_split.c		\

OBJ = $(SRC:.c=.o)

%.o: %.c
	gcc -Wall -Werror -Wextra -g -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
		gcc -Wall -Werror -Wextra -g $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re : fclean all
