/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:24:25 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/07/16 17:16:55 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

unsigned long	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char *str, int start, int len)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str || !*str || (unsigned long)start >= ft_strlen(str))
		return (free(str), NULL);
	ret = malloc((len + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < len && str[start] != '\0')
	{
		ret[i] = str[start];
		start++;
		i++;
	}
	ret[i] = '\0';
	return (free(str), ret);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*ret;
	size_t	z;
	size_t	lens1;

	if (!s1)
		return (NULL);
	lens1 = ft_strlen(s1);
	z = 0;
	i = 0;
	ret = malloc((lens1 + ft_strlen(s2) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (i < lens1)
	{
		ret[i] = s1[i];
		i++;
	}
	while (z < ft_strlen(s2))
	{
		ret[i + z] = s2[z];
		z++;
	}
	ret[i + z] = '\0';
	return (free((char *)s1), ret);
}

char	*update(char *stack, int lenline)
{
	if (!stack)
		return (NULL);
	return (ft_substr(stack, lenline, ft_strlen(stack) - lenline));
}

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
