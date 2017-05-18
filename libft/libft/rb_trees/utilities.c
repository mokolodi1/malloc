/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 15:14:36 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/18 15:20:37 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

