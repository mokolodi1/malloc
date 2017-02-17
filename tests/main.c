/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:29:16 by tfleming          #+#    #+#             */
/*   Updated: 2017/02/17 13:02:28 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <unistd.h>
#include <string.h>
#include "malloc.h"

#define		TEST_UP_TO	10

int			main()
{
	printf("getpagesize: %d\n", getpagesize());

	size_t	i;
	char	*malloced[TEST_UP_TO];

	printf("asdf");

	i = 0;
	while (i < TEST_UP_TO)
	{
		printf("hello");
		malloced[i] = (char*)malloc(i + 1);
		memset(malloced[i], 'y', i - 1);
		malloced[i][i] = '\0';
		i++;
	}
	while (i < TEST_UP_TO)
	{
		if (strlen(malloced[i]) != i) {
			printf("Failed with size = %zu\n", i);
		}
		i++;
	}
	return (0);
}
