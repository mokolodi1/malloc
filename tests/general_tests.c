/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:29:16 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/26 15:55:16 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include <string.h>
#include "malloc.h"

void		alloc_and_free(size_t repititions, size_t size)
{
	size_t	i;
	char	*malloced[repititions];

	ft_putstr("\nAbout to allocate ");
	put_size_t(size);
	ft_putstr(" bytes ");
	put_size_t(repititions);
	ft_putstr(" times...\n");
	show_alloc_mem();
	i = 0;
	while (i < repititions)
	{
		malloced[i] = (char*)malloc(size);
		memset(malloced[i], 'y', size - 1);
		malloced[i][size - 1] = '\0';
		i++;
	}
	show_alloc_mem();
	i = 0;
	while (i < repititions)
	{
		if (strlen(malloced[i]) != size - 1)
			ft_putstr("Failed!");
		free(malloced[i]);
		i++;
	}
	show_alloc_mem();
}

int			main()
{
	ft_putstr("Starting testing program...\n");
	ft_putstr("getpagesize: ");
	put_size_t(getpagesize());
	ft_putstr("\n");
	alloc_and_free(4, 64);
	alloc_and_free(4, 1024);
	alloc_and_free(4, 4096);
}
