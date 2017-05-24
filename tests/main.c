/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:29:16 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/24 16:33:38 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
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
		free(malloced[i]);
		i++;
	}
	printf("Done testing!\n");
	return (0);
}

int			main()
{
	// printf("Starting testing program!\n");
	// printf("getpagesize: %d\n", getpagesize());
	show_alloc_mem();
	// printf("About to allocate 8 bytes 4 times.\n");
	// many_of_size(4, 8);
	// show_alloc_mem();
}
