/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:14:42 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/26 21:20:28 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					free_allocation(t_alloc_metadata *allocation
											, t_alloc_info *info)
{
	if (info)
	{
		allocation->mmap->allocations--;
		if (allocation->mmap->allocations == 0)
		{
			if (allocation->mmap == info->current_mmap)
				info->next_location = info->current_mmap + 1;
			else
			{
				ft_list_remove(&info->existing_mmaps, allocation->mmap);
				munmap(allocation->mmap, info->mmap_size);
			}
		}
	}
	else
		munmap(allocation, allocation->size + sizeof(t_alloc_metadata));
}

int						free_in_list(void *to_free, t_list **current
										, t_alloc_info *info)
{
	t_alloc_metadata	*old_current;
	
	while (*current)
	{
		if ((*current)->data == to_free)
		{
			old_current = (t_alloc_metadata*)*current;
			*current = (*current)->next;
			free_allocation(old_current, info);
			return (TRUE);
		}
		current = &(*current)->next;
	}
	return (FALSE);
}

void					wrapped_free(void *to_free)
{
	int					found;
	t_alloc_env			*env;

	if (!to_free || !(env = get_alloc_env()))
		return ;
	found = FALSE;
	found = free_in_list(to_free, &env->tiny.allocations, &env->tiny);
	if (!found)
		found = free_in_list(to_free, &env->medium.allocations, &env->medium);
	if (!found)
		free_in_list(to_free, &env->large_mmaps, NULL);
}

void					free(void *to_free)
{
	pthread_mutex_lock(get_mutex());
	wrapped_free(to_free);
	pthread_mutex_unlock(get_mutex());
}
