/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:43:52 by tfleming          #+#    #+#             */
/*   Updated: 2017/02/17 13:01:54 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <errno.h>
# include "libft.h"

// TODO: change these
# define TINY_SIZE 8
# define MEDIUM_SIZE 64

/*
** *_mmaps stores all of the mmaps made for that size
** *_allocations stores all of the malloc return values for that size
** *_next_location caches the next location in the current mmap for that size
**
** The first item on the list is the freshest.
*/

typedef struct		s_alloc_type {
	t_list			*existing_mmaps;
	t_list			*allocations;
	size_t			next_location;
	size_t			max_location;
	size_t			bytes_per_mmap;
}					t_alloc_type;

typedef struct		s_alloc_data {
	t_alloc_type	tiny;
	t_alloc_type	medium;
	t_list			*large_mmaps;
}					t_alloc_data;

/*
** Public functions
*/

void				*malloc(size_t size);

/*
** Utilities
*/

extern t_alloc_data	*g_alloc_data;

t_alloc_data		*get_alloc_data();
void				*get_new_mmap(size_t size);

// void				free(void *ptr);
// void				*realloc(void *ptr, size_t size);
// void				show_alloc_mem();
// t_alloc_data				*alloc_data();

#endif
