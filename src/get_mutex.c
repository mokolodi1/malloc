/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_mutex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:56:18 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/29 14:56:21 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

pthread_mutex_t		*get_mutex(void)
{
	static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

	return (&mutex);
}
