/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alloc_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/17 00:59:05 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/26 15:54:16 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_alloc_env		*g_alloc_env = NULL;

void			setup_alloc_env(void)
{
	int			pagesize;
	size_t		tiny_size;
	size_t		medium_size;

	g_alloc_env = get_new_mmap(sizeof(t_alloc_env));
	if (!g_alloc_env)
		return ;
	ft_bzero(g_alloc_env, sizeof(t_alloc_env));
	tiny_size = (TINY_SIZE + sizeof(t_metadata)) * MALLOCS_PER_SIZE;
	medium_size = (MEDIUM_SIZE + sizeof(t_metadata)) * MALLOCS_PER_SIZE;
	pagesize = getpagesize();
	g_alloc_env->tiny.bytes_per_mmap =
			tiny_size + (pagesize - tiny_size % pagesize);
	
	g_alloc_env->medium.bytes_per_mmap =
			medium_size + (pagesize - medium_size % pagesize);
}

t_alloc_env		*get_alloc_env(void)
{
	if (!g_alloc_env)
		setup_alloc_env();
	return (g_alloc_env);
}
