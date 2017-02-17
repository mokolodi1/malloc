/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:30:03 by tfleming          #+#    #+#             */
/*   Updated: 2017/02/17 01:40:45 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void				*get_new_mmap(size_t size)
{
	return (mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE
					, -1, 0));
}

void				*alloc_non_large(t_alloc_type *type, size_t size)
{
	// check if we need to create a new mmap and create a new one if necessary
	if (type->next_location + size >= type->max_location)
	{
		ft_list_push_front(&type->existing_mmaps, get_new_mmap(size));
		// type->existing_mmaps->data
		// I'M RIGHT HERE
	}
	// figure out what to return
	// add the new return value onto the allocations list
	// update next_location
	// return
}

void				*alloc_large(t_list **existing_mmaps, size)
{
	void			*new_mmap;

	new_mmap = get_new_mmap(size);
	ft_list_push_front(existing_mmaps, new_mmap);
	return (new_mmap);
}

void				*malloc(size_t size)
{
	t_alloc_data	alloc_data;

	alloc_data = get_alloc_data();
	size += sizeof(t_list);
	if (size <= TINY_MAX)
		return alloc_non_large(&alloc_data->tiny, size);
	if (size <= MEDIUM_MAX)
		return alloc_non_large(&alloc_data->medium, size);
	return alloc_large(&alloc_data->large_mmaps, size)
}
