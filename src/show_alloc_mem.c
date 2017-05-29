/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 10:53:09 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/29 14:54:02 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t					print_mmaps(t_list *current, size_t mmap_size)
{
	size_t				total_mmapped;

	total_mmapped = 0;
	if (!current)
		ft_putstr(" None\n");
	else
	{
		ft_putchar('\n');
		while (current)
		{
			ft_putstr("    ");
			print_pointer(current);
			ft_putstr(" - ");
			print_pointer(current + mmap_size);
			ft_putstr("\n");
			total_mmapped += mmap_size;
			current = current->next;
		}
	}
	return (total_mmapped);
}

size_t					print_all_mmaps(void)
{
	size_t				total_mmapped;

	total_mmapped = 0;
	ft_putstr("  TINY mmaps (");
	put_size_t(g_alloc_env->tiny.mmap_size);
	ft_putstr(" bytes per mmap):");
	total_mmapped += print_mmaps(g_alloc_env->tiny.existing_mmaps
				, g_alloc_env->tiny.mmap_size);
	ft_putstr("  MEDIUM mmaps (");
	put_size_t(g_alloc_env->medium.mmap_size);
	ft_putstr(" bytes per mmap):");
	total_mmapped += print_mmaps(g_alloc_env->medium.existing_mmaps
				, g_alloc_env->medium.mmap_size);
	return (total_mmapped);
}

size_t					print_allocations(t_list *current)
{
	t_alloc_metadata	*allocation;
	size_t				total_allocced;

	total_allocced = 0;
	if (!current)
		ft_putstr(" None\n");
	else
	{
		ft_putchar('\n');
		while (current)
		{
			ft_putstr("    ");
			allocation = (t_alloc_metadata*)current;
			print_pointer(allocation->list_element.data);
			ft_putstr(" - ");
			print_pointer(allocation->list_element.data
							+ allocation->size);
			ft_putstr(" : ");
			put_size_t(allocation->size);
			ft_putchar('\n');
			total_allocced += allocation->size;
			current = current->next;
		}
	}
	return (total_allocced);
}

void					wrapped_show_alloc_mem(t_alloc_env *env)
{
	size_t				total_mmapped;
	size_t				total_allocced;

	total_mmapped = print_all_mmaps();
	ft_putstr("  TINY allocations (up to ");
	put_size_t(TINY_SIZE);
	ft_putstr(" bytes):");
	total_allocced = 0;
	total_allocced += print_allocations(env->tiny.allocations);
	ft_putstr("  MEDIUM allocations (up to ");
	put_size_t(MEDIUM_SIZE);
	ft_putstr(" bytes):");
	total_allocced += print_allocations(env->medium.allocations);
	ft_putstr("  LARGE allocations (larger than ");
	put_size_t(MEDIUM_SIZE);
	ft_putstr(" bytes):");
	total_mmapped += total_allocced += print_allocations(env->large_mmaps);
	ft_putstr("TOTAL: ");
	put_size_t(total_allocced);
	ft_putstr(" bytes allocated, ");
	put_size_t(total_mmapped);
	ft_putstr(" bytes mmapped.\n");
}

void					show_alloc_mem(void)
{
	t_alloc_env			*env;

	pthread_mutex_lock(get_mutex());
	env = get_alloc_env();
	if (!env)
		return ;
	ft_putstr("Showing allocated memory:\n");
	wrapped_show_alloc_mem(env);
	pthread_mutex_unlock(get_mutex());
}
