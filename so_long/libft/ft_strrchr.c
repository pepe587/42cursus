/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:22:20 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/02 13:54:24 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char			*result;
	unsigned char	ch;
	int				i;
	int				z;

	z = -1;
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
			z = i;
		i++;
	}
	if (z > -1)
		return ((&result[z]));
	else
		return (0);
}
