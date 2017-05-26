# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/24 14:34:05 by tfleming          #+#    #+#              #
#    Updated: 2017/05/26 16:35:25 by tfleming         ###   ########.fr        #
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
		src/get_alloc_env.c \
		src/utilities.c \
		src/free.c \
		src/realloc.c \
		src/show_alloc_mem.c

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror -g

%.o: %.c
	$(CC) -o $@ -c $< $(HEADERS)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	$(CC) -shared -o $@ $(OBJ) $(LIBFT)
	@ln -sf $(NAME) libft_malloc.so

clean:
	make clean -C libft/
	@rm -f $(OBJ)

fclean: clean
	make fclean -C libft/
	@rm -f $(NAME)
	@rm -f libft_malloc.so

re: fclean all
