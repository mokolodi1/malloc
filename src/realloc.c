/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 16:08:17 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/26 17:13:15 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "malloc.h"

void				*realloc_list(void *old_pointer, size_t size
									, t_list **current, int is_large)
{
	t_metadata		*metadata;
	void			*new_memory;

	while (*current)
	{
		if ((*current)->data == old_pointer)
		{
			new_memory = malloc(size);
			metadata = (t_metadata*)*current;
			ft_memcpy(new_memory, old_pointer
						, metadata->size < size ? metadata->size : size);
			*current = (*current)->next;
			if (is_large)
				munmap(metadata, metadata->size + sizeof(t_metadata));
			return (new_memory);
		}
		current = &(*current)->next;
	}
	return (NULL);
}

void				*realloc(void *old_pointer, size_t size)
{
	void			*new_memory;
	t_alloc_env		*env;

	if (!old_pointer)
		return (malloc(size));
	if (!(env = get_alloc_env()))
		return (NULL);
	new_memory = realloc_list(old_pointer, size, &env->tiny.allocations, FALSE);
	if (!new_memory)
		new_memory = realloc_list(old_pointer, size, &env->medium.allocations
									, FALSE);
	if (!new_memory)
		new_memory = realloc_list(old_pointer, size, &env->large_mmaps, TRUE);
	if (!new_memory)
		new_memory = malloc(size);
	return (new_memory);
}
