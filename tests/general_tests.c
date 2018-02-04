/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:29:16 by tfleming          #+#    #+#             */
/*   Updated: 2017/12/06 15:12:28 by tfleming         ###   ########.fr       */
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
	ft_putstr(" times.\n");
	show_alloc_mem();
	i = 0;
	while (i < repititions)
	{
		malloced[i] = (char*)malloc(size);
		ft_memset(malloced[i], 'f', size - 1);
		malloced[i][size - 1] = '\0';
		if (strlen(malloced[i]) != size - 1)
		{
			ft_putstr("FAILED before being done!\n");
			exit(1);
		}
		i++;
	}
	ft_putstr("Allocated the memory.\n");
	show_alloc_mem();
	i = 0;
	while (i < repititions)
	{
		if (strlen(malloced[i]) != size - 1)
		{
			ft_putstr("FAILED!?!\n");
			exit(1);
		}
		free(malloced[i]);
		i++;
	}
	ft_putstr("Freed the memory.\n");
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
		ft_putstr("\n");
		current = (char*)realloc(current, current_size);
		if (current_size > 0)
		{
			ft_memset(current, 'f', current_size);
			current[current_size - 1] = '\0';
			if (ft_strlen(current) != current_size - 1)
			{
				ft_putstr("FAILED!");
				exit(1);
			}
		}
		current_size += step;
		ft_putstr("\n");
		show_alloc_mem();
		ft_putstr("\n");
	}
	free(current);
	ft_putstr("Freed the last allocated memory.\n");
	show_alloc_mem();
}

void		try_every_size_up_to(size_t max, size_t step)
{
	size_t	i;
	void	*allocations[max];

	ft_putstr("Starting out try every size up to.\n");
	show_alloc_mem();
	i = 0;
	while (i < max)
	{
		allocations[i] = malloc(i);
		i += step;
	}
	ft_putstr("Mallocced everything.\n");
	show_alloc_mem();
	i = 0;
	while (i < max)
	{
		free(allocations[i]);
		i += step;
	}
	ft_putstr("Freed everything.\n");
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
	ft_putstr(" times.\n");
	show_alloc_mem();
	i = 0;
	while (i < repititions)
	{
		result = (char*)malloc(size);
		ft_memset(result, 'f', size - 1);
		result[size - 1] = '\0';
		if (strlen(result) != size - 1)
		{
			ft_putstr("FAILED before being done!\n");
			exit(1);
		}
		free(result);
		i++;
	}
	ft_putstr("Done.\n");
	show_alloc_mem();
}

int			main(void)
{
	ft_putstr("Starting testing program...\n");
	ft_putstr("getpagesize: ");
	put_size_t(getpagesize());
	ft_putstr("\n");

	try_every_size_up_to(5000, 16);
	alloc_and_free(5000, 1);
	alloc_and_free(1, 64);
	alloc_and_free(30, 64);
	alloc_and_free(2000, 64);
	alloc_and_free(1, 1024);
	alloc_and_free(30, 1024);
	alloc_and_free(2000, 1024);
	alloc_and_free(1, 4096);
	alloc_and_free(30, 4096);
	alloc_and_free(2000, 4096);
	growing_realloc(5000, 16);
	free_as_you_go(1024, 200);
	free_as_you_go(1024, 1024);
	free_as_you_go(1024, 4096);
}
