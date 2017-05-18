/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 18:04:10 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/16 18:11:10 by tfleming         ###   ########.fr       */
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
	void			*new_mmap;

	new_mmap = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE
					, -1, 0);
	if (new_mmap == MAP_FAILED)
		return (NULL);
	return new_mmap;
}
