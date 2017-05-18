/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:30:03 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/18 14:15:27 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				*alloc_non_large(t_alloc_type *type, size_t size)
{
	void			*new_memory;

	if (type->next_location + size >= type->max_location)
	{
		new_memory = get_new_mmap(type->bytes_per_mmap);
		if (!new_memory)
			return (NULL);
		type->next_location = new_memory + sizeof(t_list);
		type->max_location = new_memory + type->bytes_per_mmap;
		list_push_front(&type->existing_mmaps, new_memory, new_memory);
	}
	new_memory = type->next_location + sizeof(t_list);
	list_push_front(&type->allocations, type->next_location, new_memory);
	type->next_location += size;
	return (new_memory);
}

void				*alloc_large(t_list **existing_mmaps, size_t size)
{
	void			*new_memory;

	new_memory = get_new_mmap(size);
	if (!new_memory)
		return (NULL);
	list_push_front(existing_mmaps, new_memory, new_memory + sizeof(t_list));
	return (new_memory);
}

void				*malloc(size_t size)
{
	t_alloc_data	*alloc_data;

	alloc_data = get_alloc_data();
	if (!alloc_data)
		return (NULL);
	size += sizeof(t_list);
	if (size <= TINY_SIZE)
		return alloc_non_large(&alloc_data->tiny, size);
	if (size <= MEDIUM_SIZE)
		return alloc_non_large(&alloc_data->medium, size);
	return alloc_large(&alloc_data->large_mmaps, size);
}
