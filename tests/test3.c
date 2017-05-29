/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:57:53 by tfleming          #+#    #+#             */
/*   Updated: 2017/05/29 15:00:57 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

#define M (1024 * 1024)

void		print(char *s)
{
	write(1, s, strlen(s));
}

void		realloc_normal(void)
{
	char	*addr1;
	char	*addr3;

	addr1 = (char*)malloc(16 * M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr3 = (char*)realloc(addr1, 128 * M);
	addr3[127 * M] = 42;
	print(addr3);
}

void		realloc_pp(void)
{
	char	*addr1;
	char	*addr2;
	char	*addr3;

	addr1 = (char*)malloc(16 * M);
	strcpy(addr1, "Bonjours\n");
	print(addr1);
	addr2 = (char*)malloc(16 * M);
	addr3 = (char*)realloc(addr1, 128 * M);
	addr3[127 * M] = 42;
	print(addr3);
}

int			main(void)
{
	realloc_normal();
	realloc_pp();
	return (0);
}
