/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 14:14:42 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/19 18:35:56 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int					compare_locations(t_allocation *first, t_allocation *second)
{
	return (first->location == second->location);
}

void				free(void *pointer)
{
	t_list			*list_element;
	t_alloc_env		*env;
	t_allocation	allocation;

	if (!pointer || !g_alloc_data)
		return ;
	allocation->location = pointer;
	list_element = ft_list_find(g_alloc_data->allocations, &allocation,
							&compare_locations);
	allocation = list_element->data;
	if (list_element && list_element->type == LARGE) {
		
		munmap(list_element->, list_element->size);
	}
	else if (list_element) {
		
	}
	list_element->
}
