/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:43:52 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/26 15:51:20 by tfleming         ###   ########.fr       */
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

# define TINY_SIZE 64
# define MEDIUM_SIZE 1024
# define MALLOCS_PER_SIZE 100

# define TRUE 1
# define FALSE 0

/*
** NOTE: I take advantage of the fact that the memory location for
** list_element is the same as the struct itself, so order matters for
** t_metadata.
*/

typedef struct		s_metadata {
	t_list			list_element;
	size_t			size;
}					t_metadata;

/*
** - existing_mmaps stores all of the mmaps made for that size
** - allocations stores all of the malloc return values for that size
** - next_location caches the next location in the current mmap for
**   that size
** - max_location is the (exclusive) end of the current mmap
**
** The first item on the list is the freshest.
*/

typedef struct		s_alloc_info {
	t_list			*existing_mmaps;
	t_list			*allocations;
	void			*next_location;
	void			*max_location;
	size_t			bytes_per_mmap;
}					t_alloc_info;

typedef struct		s_alloc_env {
	t_alloc_info	tiny;
	t_alloc_info	medium;
	t_list			*large_mmaps;
}					t_alloc_env;

/*
** Public functions
*/

void				*malloc(size_t size);
void				free(void *ptr);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();

/*
** Utilities
*/

extern t_alloc_env	*g_alloc_env;

t_alloc_env			*get_alloc_env();
void				list_push_front(t_list **begin_list, t_list *list_element
									, void *data);
void				*get_new_mmap(size_t size);
void				put_size_t(size_t number);
void				print_pointer(uintmax_t pointer);

#endif
