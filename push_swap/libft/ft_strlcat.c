/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:20:56 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/02 15:20:55 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	size;

	size = 0;
	i = 0;
	while (dst[size])
		size++;
	while (src[i] && size + i + 1 < dstsize)
	{
		dst[size + i] = src[i];
		i++;
	}
	dst[size + i] = '\0';
	while (src[i])
		i++;
	if (dstsize > size)
		return (size + i);
	else
		return (dstsize + i);
}
