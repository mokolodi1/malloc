/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:29:16 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/26 21:17:08 by tfleming         ###   ########.fr       */
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
	ft_putstr(" times. ");
	show_alloc_mem();
	i = 0;
	while (i < repititions)
	{
		malloced[i] = (char*)malloc(size);
		ft_memset(malloced[i], 'f', size - 1);
		malloced[i][size - 1] = '\0';
		if (strlen(malloced[i]) != size - 1)
			ft_putstr("FAILED before being done!\n");
		i++;
	}
	ft_putstr("Allocated the memory. ");
	show_alloc_mem();
	i = 0;
	while (i < repititions)
	{
		if (strlen(malloced[i]) != size - 1)
			ft_putstr("FAILED!?!\n");
		free(malloced[i]);
		i++;
	}
	ft_putstr("Freed the memory. ");
	show_alloc_mem();
}

void		growing_realloc(size_t max_size, size_t step)
{
	size_t	current_size;
	char	*current;
	
	ft_putstr("\nGrowing realloc...\n");
	current_size = 0;
	current = NULL;
	while (current_size <= max_size)
	{
		ft_putstr("Allocating: ");
		put_size_t(current_size);
		current = (char*)realloc(current, current_size);
		if (current_size > 0)
		{
			ft_memset(current, 'f', current_size);
			current[current_size - 1] = '\0';
			if (ft_strlen(current) != current_size - 1)
				ft_putstr("FAILED!");
		}
		current_size += step;
		ft_putstr("\t");
		show_alloc_mem();
		ft_putstr("\n");
	}
	free(current);
	ft_putstr("Freed the last allocated memory. ");
	show_alloc_mem();
}

void		try_every_size_up_to(size_t max, size_t step)
{
	size_t	i;
	void	*allocations[max];

	ft_putstr("Starting out. ");
	show_alloc_mem();
	i = 0;
	while (i < max)
	{
		allocations[i] = malloc(i);
		i += step;
	}
	ft_putstr("Mallocced everything. ");
	show_alloc_mem();
	i = 0;
	while (i < max)
	{
		free(allocations[i]);
		i += step;
	}
	ft_putstr("Freed everything. ");
	show_alloc_mem();
}

void		free_as_you_go(size_t repititions, size_t size)
{
	size_t	i;
	char	*result;
	
	ft_putstr("\nAbout to allocate then free ");
	put_size_t(size);
	ft_putstr(" bytes ");
	put_size_t(repititions);
	ft_putstr(" times. ");
	show_alloc_mem();
	i = 0;
	while (i < repititions)
	{
		result = (char*)malloc(size);
		ft_memset(result, 'f', size - 1);
		result[size - 1] = '\0';
		if (strlen(result) != size - 1)
			ft_putstr("FAILED before being done!\n");
		free(result);
		i++;
	}
	ft_putstr("Done. ");
	show_alloc_mem();
}

int			main()
{
	ft_putstr("Starting testing program...\n");
	ft_putstr("getpagesize: ");
	put_size_t(getpagesize());
	ft_putstr("\n");
	try_every_size_up_to(1200, 1);
	alloc_and_free(200, 64);
	alloc_and_free(200, 1024);
	alloc_and_free(200, 4096);
	growing_realloc(1200, 16);
	free_as_you_go(1024, 1024);
}
