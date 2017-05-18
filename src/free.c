
#include "malloc.h"

void				free_in_list(void *pointer, t_list *allocations, int is_large_mmap)
{
	
}

void				free(void *pointer)
{
	t_list			*to_free;

	if (!pointer || !g_alloc_data)
		return ;
	
	to_free = ft_list_find(
}
