/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:51:52 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/02 13:28:57 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	size_t				i;
	unsigned char		ch;

	ch = c;
	i = 0;
	p = s;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (p[i] == ch)
			return ((void *)(p + i));
	i++;
	}
	return (0);
}
