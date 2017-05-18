/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:33:48 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/18 17:39:31 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "rb_trees.h"

void				*ft_rb_get(t_rb_tree *tree, void *key)
{
	t_rb_node		*current;
	int				comparison;

	current = tree->root;
	while (current)
	{
		comparison = tree->compare(key, current->key);
		if (comparison < 0)
			current = current->left;
		else if (comparison > 0)
			current = current->right;
		else
			return current->value;
	}
	return (NULL);
}
