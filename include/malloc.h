/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:43:52 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/16 18:12:35 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"

// TODO: do these have to be a multiple of getpagesize()?
# define TINY_SIZE 8
# define MEDIUM_SIZE 64

/*
** - existing_mmaps stores all of the mmaps made for that size
** - allocations stores all of the malloc return values for that size
** - next_location caches the next location in the current mmap for
**   that size
** - max_location is the (exclusive) end of the current mmap
**
** The first item on the list is the freshest.
*/

typedef struct		s_alloc_type {
	t_list			*existing_mmaps;
	t_list			*allocations;
	void			*next_location;
	void			*max_location;
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
void				list_push_front(t_list **begin_list , t_list *list_element
										, void *data);
void				*get_new_mmap(size_t size);

// void				free(void *ptr);
// void				*realloc(void *ptr, size_t size);
// void				show_alloc_mem();
// t_alloc_data				*alloc_data();

#endif
