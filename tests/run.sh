# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    run.sh                                             :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/16 22:27:02 by tfleming          #+#    #+#              #
#    Updated: 2017/02/16 23:37:09 by tfleming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# create the library
make -C ..

# compile the main
gcc -Wall -Wextra -Werror -I ../libft/include -o test_malloc ../libft/libft.a main.c

# set some environmental variables so it uses our malloc
export DYLD_LIBRARY_PATH=..
export DYLD_INSERT_LIBRARIES=../libft_malloc.so
export DYLD_FORCE_FLAT_NAMESPACE=1

# run the tests
./test_malloc
