/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 18:04:10 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/26 14:33:08 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
** list_push_front is just like ft_list_push_front except it takes the
** new t_list as a parameter so that malloc isn't recursive ;)
*/

void				list_push_front(t_list **begin_list, t_list *list_element
									, void *data)
{
	list_element->data = data;
	list_element->next = *begin_list;
	*begin_list = list_element;
}

void				*get_new_mmap(size_t size)
{
	void			*new_mmap;

	new_mmap = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE
					, -1, 0);
	if (new_mmap == MAP_FAILED)
		return (NULL);
	return (new_mmap);
}

void				write_chars(char *first, char *now, size_t number)
{
	while (now >= first)
	{
		*now = number % 10 + '0';
		number /= 10;
		now--;
	}
}

void				put_size_t(size_t number)
{
	char	string[128 + 1];
	int		length;

	if (number == 0)
		ft_putstr("0");
	else
	{
		length = ft_count_digits_ularge(ft_abs_large(number));
		write_chars(string, string + length - 1, number);
		string[length] = '\0';
		ft_putstr(string);
	}
}

void				print_pointer(uintmax_t pointer)
{
	char			conversion[17];
	char			pointer_string[10];
	char			*current;

	ft_putstr("0x");
	ft_strcpy((char*)&conversion, "0123456789abcdef");
	pointer_string[9] = '\0';
	current = (char*)&pointer_string + 8;
	while (pointer)
	{
		*current = conversion[pointer % 16];
		pointer /= 16;
		current--;
	}
	ft_putstr(pointer_string);
}
