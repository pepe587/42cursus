/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:57:03 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/01 15:13:17 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	int				i;

	str = s;
	i = 0;
	while (n > 0)
	{
		str[i] = 0;
		n--;
		i++;
	}	
}
