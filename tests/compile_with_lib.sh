# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_with_lib.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfleming <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/26 13:51:09 by tfleming          #+#    #+#              #
#    Updated: 2017/05/26 20:49:10 by tfleming         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -g -I include -I libft/include -L. -lft_malloc $1
echo "DONE COMPILING"
