/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:30:03 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/26 18:32:27 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					*alloc_non_large(t_alloc_info *info, size_t size)
{
	t_alloc_metadata	*metadata;
	void				*new_memory;

	if (info->next_location + size + sizeof(t_alloc_metadata)
			>= info->max_location)
	{
		info->current_mmap = get_new_mmap(info->bytes_per_mmap);
		if (!info->current_mmap)
			return (NULL);
		info->next_location = info->current_mmap + sizeof(t_list);
		info->max_location = info->current_mmap + info->bytes_per_mmap;
		list_push_back(&info->existing_mmaps, &info->current_mmap->list_element
						, info->current_mmap);
	}
	metadata = (t_alloc_metadata*)info->next_location;
	metadata->size = size;
	new_memory = metadata + 1;
	list_push_back(&info->allocations, &metadata->list_element, new_memory);
	info->next_location = new_memory + size;
	return (new_memory);
}

void					*alloc_large(t_list **existing_mmaps, size_t size)
{
	t_alloc_metadata	*metadata;
	void				*new_memory;

	metadata = get_new_mmap(size + sizeof(t_alloc_metadata));
	if (!metadata)
		return (NULL);
	metadata->size = size;
	new_memory = metadata + sizeof(t_alloc_metadata);
	list_push_back(existing_mmaps, &metadata->list_element, new_memory);
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
