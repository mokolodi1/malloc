/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:29:16 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/26 17:51:20 by tfleming         ###   ########.fr       */
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

void		growing_realloc(void)
{
	size_t	current_size;
	size_t	step;
	size_t	max_size;
	void	*current;
	
	ft_putstr("\nGrowing realloc...\n");
	current_size = 0;
	step = 8;
	max_size = 32;
	current = NULL;
	while (current_size <= max_size)
	{
		ft_putstr("Just allocated: ");
		put_size_t(current_size);
		current = realloc(current, current_size);
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

void		get_a_megabyte(void)
{
	char	*addr;
	int		i;

	i = 0;
	while (i < 200)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		i++;
	}
	ft_putstr("Allocated a megabyte. ");
	show_alloc_mem();
}

int			main()
{
	ft_putstr("Starting testing program...\n");
	ft_putstr("getpagesize: ");
	put_size_t(getpagesize());
	ft_putstr("\n");
	// try_every_size_up_to(1200, 16);
	// alloc_and_free(4, 64);
	// alloc_and_free(4, 1024);
	// alloc_and_free(4, 4096);
	// growing_realloc();
	get_a_megabyte();
}
