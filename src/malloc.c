/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:30:03 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/19 18:11:04 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				*new_mmap_for_type(t_list **existing_mmaps
										, t_alloc_info *info)
{
	t_mmap			*new_mmap;

	info->current = get_new_mmap(info->bytes_per_mmap);
	if (!info->current)
		return (NULL);
	list_push_front(existing_mmaps, (t_list*)info->current, info->current);
	new_mmap = (t_mmap*)info->current + sizeof(t_list);
	new_mmap->location = info->current;
	new_mmap->size = info->bytes_per_mmap;
	info->next_location = new_mmap + sizeof(t_mmap);
	return (info->current);
}

void				*alloc_non_large(t_alloc_env *env, t_size_info *info
										, size_t size, t_alloc_type malloc_type)
{
	t_allocation	*allocation;

	size += sizeof(t_list);
	if (info->next_location + size > info->current + info->bytes_per_mmap)
	{
		if (!new_mmap_for_type(existing_mmaps, info))
			return (NULL);
	}
	allocation = (t_allocation*)info->next_location + sizeof(t_list);
	allocation->location = allocation + sizeof(t_allocation);
	allocation->type = malloc_type;
	allocation->size = size;
	list_push_front(&env->allocations, info->next_location, allocation);
	return (allocation->location);
}

void				*alloc_large(t_alloc_env *env, size_t size)
{
	t_allocation	*allocation;

	allocation = (t_allocation*)get_new_mmap(size);
	if (!allocation)
		return (NULL);
	allocation->location = (void*)allocation + sizeof(t_allocation)
			+ sizeof(t_list);
	allocation->type = LARGE;
	allocation->size = size;
	list_push_front(&env->allocations,
					(t_list*)allocation + sizeof(t_allocation), allocation);
	return (allocation->location);
}

void				*malloc(size_t size)
{
	t_alloc_env		*env;

	env = get_env();
	if (!env)
		return (NULL);
	if (size + sizeof(t_list) <= TINY_SIZE)
		return alloc_non_large(env, &env.tiny, size, TINY);
	if (size + sizeof(t_list) <= MEDIUM_SIZE)
		return alloc_non_large(env, &env.medium, size, MEDIUM);
	return alloc_large(&env->existing_mmaps, size);
}
