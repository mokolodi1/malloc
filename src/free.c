/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:14:42 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/26 15:47:41 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int					free_in_list(void *to_free, t_list **current, int is_large)
{
	void			*to_munmap;

	while (*current)
	{
		if ((*current)->data == to_free)
		{
			if (is_large)
				to_munmap = *current;
			*current = (*current)->next;
			if (is_large)
				munmap(to_munmap, ((t_metadata*)to_munmap)->size + sizeof(t_metadata));
			return (TRUE);
		}
		current = &(*current)->next;
	}
	return (FALSE);
}

void				free(void *to_free)
{
	int				found;

	if (!to_free || !g_alloc_env)
		return ;
	found = FALSE;
	found = free_in_list(to_free, &g_alloc_env->tiny.allocations, FALSE);
	if (!found)
		found = free_in_list(to_free, &g_alloc_env->medium.allocations, FALSE);
	if (!found)
		free_in_list(to_free, &g_alloc_env->large_mmaps, TRUE);
}
