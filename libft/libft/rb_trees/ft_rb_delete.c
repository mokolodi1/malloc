/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 13:49:23 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/19 14:51:43 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_trees.h"

t_rb_node			*delete(t_rb_node *node, void *key
								, int (*compare)(void*, void*))
{
	if (compare(key, node->key) < 0)
	{
		if (!is_red(node->left) && !is_red(node->left->left))
			node = move_red_left(node);
		node->left = delete(node->left, key);
	}
	else {
		if (is_red(node->left))
			node = rotate_right(node);
		if (compare(key, node->key) == 0 && node->right == NULL)
			return (NULL);
		if (!is_red(ndoe->right) && !is_red(node->right->left))
			node = move_red_right(node);
		if (compare(key, node->key) == 0)
		{
			
		}
	}
}

void				ft_rb_delete(t_rb_tree *tree, void *key)
{
	if (!get(ft_rb_get(tree, key)))
		return ;
	if (!is_red(root->left) && !is_red(root->right))
		root->color = RB_RED;
	tree->root = delete(tree->root, key);
	if (tree->root)
		root->color = RB_BLACK;
}
