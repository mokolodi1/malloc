/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:08:17 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/29 15:03:09 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "malloc.h"

void					*realloc_list(void *old_pointer, size_t size
										, t_list **current, t_alloc_info *info)
{
	t_alloc_metadata	*old_allocation;
	void				*new_memory;

	while (*current)
	{
		if ((*current)->data == old_pointer)
		{
			new_memory = wrapped_malloc(size);
			old_allocation = (t_alloc_metadata*)*current;
			ft_memcpy(new_memory, old_pointer
						, old_allocation->size < size ?
							old_allocation->size : size);
			*current = (*current)->next;
			free_allocation(old_allocation, info);
			return (new_memory);
		}
		current = &(*current)->next;
	}
	return (NULL);
}

void					*wrapped_realloc(void *old_pointer, size_t size)
{
	void				*new_memory;
	t_alloc_env			*env;

	if (!old_pointer)
		return (wrapped_malloc(size));
	if (!(env = get_alloc_env()))
		return (NULL);
	new_memory = realloc_list(old_pointer, size, &env->tiny.allocations
									, &env->tiny);
	if (!new_memory)
		new_memory = realloc_list(old_pointer, size, &env->medium.allocations
									, &env->medium);
	if (!new_memory)
		new_memory = realloc_list(old_pointer, size, &env->large_mmaps, NULL);
	return (new_memory);
}

void					*realloc(void *old_pointer, size_t size)
{
	void				*address;

	pthread_mutex_lock(get_mutex());
	address = wrapped_realloc(old_pointer, size);
	pthread_mutex_unlock(get_mutex());
	return (address);
}
