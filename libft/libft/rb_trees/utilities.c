/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:14:36 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/18 17:39:52 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "rb_trees.h"

/*
** private functions: is_red, size(t_rb_node *node)
*/

int				is_red(t_rb_node *node)
{
	if (node)
		return (node->color == RB_RED);
	return (0);
}

int				size(t_rb_node *node)
{
	if (node)
		return (node.size);
	return (0);
}

int				ft_rb_size(t_rb_tree *tree)
{
	return (size(tree->root));
}

int				ft_rb_is_empty(t_rb_tree *tree)
{
	return (tree->root == NULL);
}
