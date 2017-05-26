/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 10:53:09 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/26 20:22:17 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					print_mmaps(t_list *current, size_t bytes_per_mmap)
{
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
			print_pointer(current + bytes_per_mmap);
			ft_putstr("\n");
			current = current->next;
		}
	}
}

void					print_all_mmaps(void)
{
	ft_putstr("  TINY mmaps (");
	put_size_t(g_alloc_env->tiny.bytes_per_mmap);
	ft_putstr(" bytes per mmap):");
	print_mmaps(g_alloc_env->tiny.existing_mmaps
				, g_alloc_env->tiny.bytes_per_mmap);
	ft_putstr("  MEDIUM mmaps (");
	put_size_t(g_alloc_env->medium.bytes_per_mmap);
	ft_putstr(" bytes per mmap):");
	print_mmaps(g_alloc_env->medium.existing_mmaps
				, g_alloc_env->medium.bytes_per_mmap);
}

void					print_allocations(t_list *current)
{
	t_alloc_metadata	*allocation;

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
			current = current->next;
		}
	}
}

void					show_alloc_mem(void)
{
	t_alloc_env			*env;

	env = get_alloc_env();
	if (!env)
		return ;
	ft_putstr("Showing allocated memory:\n");
	print_all_mmaps();
	ft_putstr("  TINY allocations (up to ");
	put_size_t(TINY_SIZE);
	ft_putstr(" bytes):");
	print_allocations(env->tiny.allocations);
	ft_putstr("  MEDIUM allocations (up to ");
	put_size_t(MEDIUM_SIZE);
	ft_putstr(" bytes):");
	print_allocations(env->medium.allocations);
	ft_putstr("  LARGE allocations (larger than ");
	put_size_t(MEDIUM_SIZE);
	ft_putstr(" bytes):");
	print_allocations(env->large_mmaps);
}
