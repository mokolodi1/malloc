/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 17:40:28 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/18 17:43:51 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rb_trees.h"

t_rb_node			*create_node(void *key, void *value)
{
	t_rb_node		*new_node;

	new_node = malloc(sizeof(t_rb_node));
	new_node->key = key;
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->color = RB_RED;
	new_node->size = 1;
	return (new_node);
}

t_rb_node			*rotate_left(t_rb_node *node)
{
	
}

t_rb_node			*rotate_right(t_rb_node *node)
{
	
}

// TODO: flip_colors

t_rb_node			*put(t_rb_node *node, int (*compare)(void*, void*)
							, void *key, void *value)
{
	int				comparison;

	if (!node)
		return (create_node(key, value));
	comparison = compare(key, node->key);
	if (comparison < 0)
		node->left = put(node->left, key, value);
	else if (comparison > 0)
		node->right = put(node->right, key, value);
	else
		node->value = value;
	if (is_red(node->right) && !is_red(node->left))
		node = rotate_left(node);
	if (is_red(node->left) && is_red(node->left->left))
		node = rotate_right(node);
	if (is_red(node->left) && is_red(node->right))
		flip_colors(node);
	node->size = size(node->left) + size(node->right) + 1;
	return (node);
	
}

void				ft_rb_put(t_rb_tree *tree, void *key, void *value)
{
	put(tree->root, key, value);
	tree->root.value = RB_BLACK;
}
