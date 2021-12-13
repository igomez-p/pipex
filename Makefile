# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igomez-p <igomez-p@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 20:15:03 by igomez-p          #+#    #+#              #
#    Updated: 2021/12/13 17:40:39 by igomez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC =	pipex.c \
		src/reader.c \
		src/checker.c \
		libft/str_functions.c	\
		libft/ft_split.c		\
		#library/number_functions.c 	\
		library/mem_functions.c		\

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
