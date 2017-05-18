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

t_rb_node			*put(t_rb_node *subtree_root, void *key, void *value)
{
	
}

void				ft_rb_put(t_rb_tree *tree, void *key, void *value)
{
	put(tree->root, key, value);
	tree->root.value = RB_BLACK;
}
