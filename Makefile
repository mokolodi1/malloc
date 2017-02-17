# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 14:34:05 by tfleming          #+#    #+#              #
#    Updated: 2017/02/17 12:08:07 by tfleming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

HEADERS =	-I include/ \
			-I libft/include/

LIBFT = libft/libft.a

SRC =	src/malloc.c \
		src/get_alloc_data.c

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror

%.o: %.c
	$(CC) -o $@ -c $< $(HEADERS)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -shared -o $@ $(OBJ) $(LIBFT)
	@ln -s $(NAME) libft_malloc.so

clean:
	make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	@rm -f $(NAME)
	@rm -f libft_malloc.so

re: fclean all
