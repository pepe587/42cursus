/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:07:52 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/08 16:53:31 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const unsigned char	*s1;
	unsigned char		*s2;
	size_t				i;

	i = 0;
	s1 = src;
	s2 = dst;
	if (dst == NULL && src == NULL)
		return (0);
	while (n > 0)
	{
		s2[i] = s1[i];
		n--;
		i++;
	}
	return (dst);
}
