/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:29:16 by tfleming          #+#    #+#             */
/*   Updated: 2017/02/16 23:34:20 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

#define		TEST_UP_TO	10

int			main()
{
	size_t	i;
	char	*malloced[TEST_UP_TO];

	ft_printf("asdf");

	i = 0;
	while (i < TEST_UP_TO)
	{
		ft_printf("hello");
		malloced[i] = (char*)malloc(i + 1);
		ft_memset(malloced[i], 'y', i - 1);
		malloced[i][i] = '\0';
		i++;
	}
	while (i < TEST_UP_TO)
	{
		if (ft_strlen(malloced[i]) != i) {
			ft_printf("Failed with size = %d\n", i);
		}
		i++;
	}
	return (0);
}
