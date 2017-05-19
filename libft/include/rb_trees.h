/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_trees.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:17:13 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/19 13:59:01 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREES_H
# define RB_TREES_H

# import "libft.h"

# define			RB_RED		1
# define			RB_BLACK	0

/*
** Utilities
*/

int					is_red(t_rb_node *node);
int					size(t_rb_node *node);
t_rb_node			*rotate_left(t_rb_node *node);
t_rb_node			*rotate_right(t_rb_node *node);

#endif
