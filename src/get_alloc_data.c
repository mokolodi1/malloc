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
	if (!g_alloc_data)
		return ;
	ft_bzero(g_alloc_data, sizeof(t_alloc_data));
	pagesize = getpagesize();
	tiny_size = pagesize;
	medium_size = pagesize;
	while (tiny_size < 100 * TINY_SIZE + sizeof(t_list))
		tiny_size *= 2;
	while (medium_size < 100 * MEDIUM_SIZE + sizeof(t_list))
		medium_size *= 2;
	g_alloc_data->tiny.bytes_per_mmap = tiny_size;
	g_alloc_data->medium.bytes_per_mmap = medium_size;
	printf("tiny_bytes_per_mmap: %zu\n", tiny_size);
	printf("medium_bytes_per_mmap: %zu\n", medium_size);
}

t_alloc_data	*get_alloc_data()
{
	if (!g_alloc_data)
		setup_alloc_data();
	return (g_alloc_data);
}
