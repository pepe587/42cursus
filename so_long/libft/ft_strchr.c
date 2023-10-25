/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:45:55 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/02 13:47:35 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strchr(const char *str, int c)
{
	char			*result;
	unsigned char	ch;
	int				i;

	result = (char *)str;
	ch = c;
	i = 0;
	if (ch == '\0')
	{
		while (result[i])
			i++;
		return (&result[i]);
	}
	while (result[i] != '\0')
	{
		if (result[i] == ch)
			return (&result[i]);
		i++;
	}
	return (0);
}
