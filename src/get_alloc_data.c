/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alloc_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 00:59:05 by tfleming          #+#    #+#             */
/*   Updated: 2017/02/17 13:04:23 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_alloc_data	*g_alloc_data = NULL;

void			setup_alloc_data()
{
	int			pagesize;

	ft_bzero(g_alloc_data, sizeof(t_alloc_data));
	pagesize = getpagesize();
	g_alloc_data->tiny->bytes_per_mmap = TINY_SIZE * pagesize + sizeof(t_list);
	g_alloc_data->medium->bytes_per_mmap = MEDIUM_SIZE * pagesize
											+ sizeof(t_list);
}

t_data			*get_alloc_data()
{
	if (!g_alloc_data)
		setup_alloc_data()
	return (g_alloc_data);
}
