/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 17:01:28 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/23 19:31:00 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	memo;
	void	*pt;

	memo = count * size;
	pt = malloc(memo);
	if (pt == NULL)
		return (0);
	ft_memset(pt, 0, count * size);
	return (pt);
}
