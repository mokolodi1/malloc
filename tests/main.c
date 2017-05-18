/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:29:16 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/18 14:30:28 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <unistd.h>
#include <string.h>
#include "malloc.h"

int			many_of_size(size_t repititions, size_t size)
{
	size_t	i;
	char	*malloced[repititions];

	printf("About to start maloccing...\n");
	i = 0;
	while (i < repititions)
	{
		printf("Testing: %zu\n", i);
		malloced[i] = (char*)malloc(size);
		memset(malloced[i], 'y', size - 1);
		malloced[i][size - 1] = '\0';
		i++;
	}
	printf("Checking the memory is still there and freeing...\n");
	i = 0;
	while (i < repititions)
	{
		if (strlen(malloced[i]) != size - 1) {
			printf("Failed with size = %zu\n", i);
		}
		free(malloced[9]);
		i++;
	}
	printf("Done testing!\n");
	return (0);
}

int			main()
{
	printf("Starting testing program");
	printf("getpagesize: %d\n", getpagesize());
	many_of_size(100, 8);
}
