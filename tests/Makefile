# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 12:53:54 by tfleming          #+#    #+#              #
#    Updated: 2017/05/16 18:14:30 by tfleming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_malloc

HEADERS =	-I ../include/ \
			-I ../libft/include

SRC =		main.c

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror -g

%.o: %.c
	$(CC) -o $@ -c $< $(HEADERS)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ..
	$(CC) -shared -o $@ $(OBJ)
	$(CC) -o $(NAME) $(OBJ) ../src/malloc.o ../src/get_alloc_data.o ../libft/libft.a ../src/utilities.o

clean:
	make clean -C ..
	@rm -f $(OBJ)

fclean: clean
	make fclean -C ..
	@rm -f $(NAME)

re: fclean all
