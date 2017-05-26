/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 19:00:03 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/26 19:15:16 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "libft.h"

void				ft_list_remove(t_list **current, void *target)
{
	while (*current)
	{
		if ((*current)->data == target)
		{
			*current = (*current)->next;
			return ;
		}
		current = &(*current)->next;
	}
}
