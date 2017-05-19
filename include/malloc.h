/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:43:52 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/19 17:30:19 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MALLOC_H
# define FT_MALLOC_H

/*
** Note that in all instances where I use linked lists in this
** implementation, I should be using hash maps for performance
** reasons.
*/

# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"

/*
** Tiny and medium containers must hold at least 100 mallocs.
*/

# define TINY_SIZE 8
# define MEDIUM_SIZE 64
# define MALLOCS_PER_SIZE 100

typedef enum		e_alloc_type {
	TINY, MEDIUM, LARGE
}					t_alloc_type;

typedef struct		s_allocation {
	void			*location;
	t_alloc_type	type;
	size_t			size;
}					t_allocation;

typedef struct		s_mmap {
	void			*location;
	size_t			size;
	size_t			allocation_count;
}					t_mmap;

typedef struct		s_size_info {
	void			*current;
	void			*next_location;
	size_t			bytes_per_mmap;
}					t_size_info;

typedef struct		s_alloc_env {
	t_list			*existing_mmaps;
	t_list			*allocations;
	t_alloc_type	tiny;
	t_alloc_type	medium;
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

#endif
