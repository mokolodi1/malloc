/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:30:03 by tfleming          #+#    #+#             */
/*   Updated: 2017/02/17 13:04:59 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** list_push_front is just like ft_list_push_front except it takes the
** new t_list as a parameter so that malloc isn't recursive ;)
*/

void				list_push_front(t_list **begin_list , t_list *list_element
									, void *data)
{
	list_element->data = data;
	list_element->next = *begin_list;
	*begin_list = list_element;
}

void				*get_new_mmap(size_t size)
{
	return (mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE
					, -1, 0));
}

void				*alloc_non_large(t_alloc_type *type, size_t size)
{
	void			*new_alloc;

	if (type->next_location + size >= type->max_location)
	{
		new_alloc = get_new_mmap(type->bytes_per_mmap);
		type->next_location = new_alloc;
		type->max_location = new_alloc + type->bytes_per_mmap;
		list_push_front(&type->existing_mmaps, new_alloc);
	}
	new_alloc = type->next_location + sizeof(t_list);
	list_push_front(&type->allocations, type->next_location, new_alloc);
	type->next_location += size;
	return (new_alloc);
}

void				*alloc_large(t_list **existing_mmaps, size)
{
	void			*new_mmap;

	new_mmap = get_new_mmap(size);
	list_push_front(existing_mmaps, new_mmap, new_mmap + sizeof(t_list));
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
