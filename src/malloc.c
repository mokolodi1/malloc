/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:30:03 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/24 16:32:08 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					*alloc_non_large(t_alloc_info *info, size_t size)
{
	t_metadata			*metadata;
	void				*new_memory;

	if (info->next_location + size + sizeof(t_metadata) >= info->max_location)
	{
		new_memory = get_new_mmap(info->bytes_per_mmap);
		if (!new_memory)
			return (NULL);
		info->next_location = new_memory + sizeof(t_list);
		info->max_location = new_memory + info->bytes_per_mmap;
		list_push_front(&info->existing_mmaps, new_memory, new_memory);
	}
	metadata = (t_metadata*)info->next_location;
	metadata->size = size;
	new_memory = metadata + sizeof(t_metadata);
	list_push_front(&info->allocations, &metadata->list_element, new_memory);
	info->next_location = new_memory + size;
	return (new_memory);
}

void					*alloc_large(t_list **existing_mmaps, size_t size)
{
	t_metadata			*metadata;
	void				*new_memory;

	metadata = get_new_mmap(size + sizeof(t_metadata));
	if (!metadata)
		return (NULL);
	metadata->size = size;
	new_memory = metadata + sizeof(t_metadata);
	list_push_front(existing_mmaps, &metadata->list_element, new_memory);
	return (new_memory);
}

void					*malloc(size_t size)
{
	t_alloc_env			*env;

	env = get_alloc_env();
	if (!env)
		return (NULL);
	if (size <= TINY_SIZE)
		return alloc_non_large(&env->tiny, size);
	if (size <= MEDIUM_SIZE)
		return alloc_non_large(&env->medium, size);
	return alloc_large(&env->large_mmaps, size);
}
