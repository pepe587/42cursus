/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:55:17 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/04 13:02:31 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	z;
	size_t	size;

	size = 0;
	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	if (*haystack == '\0')
		return (0);
	while (needle[size] != '\0')
		size++;
	if (len < size || len == 0)
		return (0);
	while (i <= len - size && haystack[i] != '\0')
	{
		z = 0;
		while (haystack[z + i] == needle[z] && z < size)
			z++;
		if (z == size)
			return ((char *)(&haystack[i]));
		i++;
	}
	return (0);
}
