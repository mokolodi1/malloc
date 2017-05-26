/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:30:03 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/26 21:06:46 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					*alloc_non_large(t_alloc_info *info, size_t size)
{
	t_alloc_metadata	*allocation;
	void				*new_memory;

	if (!info->current_mmap
		|| info->next_location + size + sizeof(t_alloc_metadata)
			>= info->max_location)
	{
		info->current_mmap = get_new_mmap(info->bytes_per_mmap);
		if (!info->current_mmap)
			return (NULL);
		info->next_location = info->current_mmap + 1;
		info->max_location = (void*)info->current_mmap + info->bytes_per_mmap;
		list_push_back(&info->existing_mmaps, &info->current_mmap->list_element
						, info->current_mmap);
	}
	allocation = (t_alloc_metadata*)info->next_location;
	allocation->size = size;
	allocation->mmap = info->current_mmap;
	new_memory = allocation + 1;
	list_push_back(&info->allocations, &allocation->list_element, new_memory);
	info->current_mmap->allocations++;
	info->next_location = (void*)allocation + size + sizeof(t_alloc_metadata);
	return (new_memory);
}

void					*alloc_large(t_list **existing_mmaps, size_t size)
{
	t_alloc_metadata	*allocation;
	void				*new_memory;

	allocation = get_new_mmap(size + sizeof(t_alloc_metadata));
	if (!allocation)
		return (NULL);
	allocation->size = size;
	new_memory = allocation + sizeof(t_alloc_metadata);
	list_push_back(existing_mmaps, &allocation->list_element, new_memory);
	return (new_memory);
}

void					*malloc(size_t size)
{
	t_alloc_env			*env;

	env = get_alloc_env();
	if (!env)
		return (NULL);
	if (size <= TINY_SIZE)
		return (alloc_non_large(&env->tiny, size));
	if (size <= MEDIUM_SIZE)
		return (alloc_non_large(&env->medium, size));
	return (alloc_large(&env->large_mmaps, size));
}
