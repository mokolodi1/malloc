/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 10:53:09 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/24 16:51:40 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				print_pointer(uintmax_t pointer)
{
	char			conversion[17];
	char			pointer_string[10];
	char			*current;

	ft_putstr("0x");
	ft_strcpy((char*)&conversion, "0123456789abcdef");
	pointer_string[9] = '\0';
	current = (char*)&pointer_string + 8;
	while (pointer)
	{
		*current = conversion[pointer % 16];
		pointer /= 16;
		current--;
	}
	ft_putstr(pointer_string);
}

void				print_mmaps(t_list *current, size_t bytes_per_mmap)
{
	if (!current)
		ft_putstr("None\n");
	while (current)
	{
		print_pointer((uintmax_t)current);
		ft_putstr(" - ");
		print_pointer((uintmax_t)current + bytes_per_mmap);
		ft_putstr("\n");
		current = current->next;
	}
}

void				print_all_mmaps()
{
	ft_putstr("TINY mmaps (");
	ft_putnbr_large_fd(g_alloc_env->tiny.bytes_per_mmap, 1);
	ft_putstr(" bytes per mmap):\n");
	print_mmaps(g_alloc_env->tiny.existing_mmaps
				, g_alloc_env->tiny.bytes_per_mmap);
	ft_putstr("MEDIUM mmaps (");
	ft_putnbr_large_fd(g_alloc_env->medium.bytes_per_mmap, 1);
	ft_putstr(" bytes per mmap):\n");
	print_mmaps(g_alloc_env->medium.existing_mmaps
				, g_alloc_env->medium.bytes_per_mmap);
}

void				show_alloc_mem()
{
	t_alloc_env		*env;

	env = get_alloc_env();
	if (!env)
		return ;
	print_all_mmaps();
	ft_putstr("TINY allocations (");
	ft_putnbr(
	:\n");
	// ft_putstr("LARGE allocations:\n");
	// ft_list_foreach(g_alloc_env->large_mmaps, &print_large_mmap);
}
