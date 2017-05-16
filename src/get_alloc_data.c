/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alloc_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 00:59:05 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/16 18:06:01 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_alloc_data	*g_alloc_data = NULL;

/*
** NOTE: type containers must hold at least 100 mallocs
*/

void			setup_alloc_data()
{
	int			pagesize;
	size_t		tiny_size;
	size_t		medium_size;

	g_alloc_data = get_new_mmap(sizeof(t_alloc_data));
	ft_bzero(g_alloc_data, sizeof(t_alloc_data));
	pagesize = getpagesize();
	tiny_size = TINY_SIZE * pagesize;
	medium_size = MEDIUM_SIZE * pagesize;
	while (tiny_size < 100 * TINY_SIZE)
		tiny_size *= 2;
	while (medium_size < 100 * MEDIUM_SIZE)
		medium_size *= 2;
	g_alloc_data->tiny.bytes_per_mmap = tiny_size + sizeof(t_list);
	g_alloc_data->medium.bytes_per_mmap = medium_size + sizeof(t_list);
}

t_alloc_data	*get_alloc_data()
{
	if (!g_alloc_data)
		setup_alloc_data();
	return (g_alloc_data);
}
