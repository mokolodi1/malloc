# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_tests.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/26 17:42:57 by tfleming          #+#    #+#              #
#    Updated: 2017/05/26 17:59:11 by tfleming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -o test0 test0.c
gcc -o test1 test1.c
gcc -o test2 test2.c
gcc -o test3 test3.c
gcc -o test4 test4.c

echo "Done compiling"

echo "Use this for compiling test5"
echo "gcc -o test5 tests/test5.c -L. -lft_malloc -I include -I libft"
