# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_suite.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/24 12:13:04 by tfleming          #+#    #+#              #
#    Updated: 2017/05/24 14:13:16 by tfleming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

echo "Compiling..."
gcc -o test0 test0.c
gcc -o test1 test1.c

echo "No malloc for base comparison:"
/usr/bin/time -l ./test0

echo "After adding a malloc:"
/usr/bin/time -l ./test1

echo "No malloc with my library:"
./run_with_malloc.sh /usr/bin/time -l ./test0

echo "With malloc with my library:"
./run_with_malloc.sh /usr/bin/time -l ./test1

echo "Removing compiled files..."
#rm test0
#rm test1
