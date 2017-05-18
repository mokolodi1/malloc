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

#define REPITITIONS		10

int			main()
{
	printf("Starting testing program");
	printf("getpagesize: %d\n", getpagesize());

	size_t	i;
	char	*malloced[REPITITIONS];

	printf("About to start maloccing...\n");
	i = 0;
	while (i < REPITITIONS)
	{
		printf("Testing: %zu\n", i);
		malloced[i] = (char*)malloc(8);
		memset(malloced[i], 'y', 8);
		malloced[i][7] = '\0';
		i++;
	}
	printf("Checking the memory is still there and freeing...\n");
	i = 0;
	while (i < REPITITIONS)
	{
		if (strlen(malloced[i]) != 7) {
			printf("Failed with size = %zu\n", i);
		}
		free(malloced[9]);
		i++;
	}
	printf("Done testing!\n");
	return (0);
}
