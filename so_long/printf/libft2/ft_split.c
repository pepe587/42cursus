/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:19:05 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/19 16:27:12 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void ft_free_result(char **result, int size)
{
	while (size > 0)
		free(result[--size]);
	free(result);
}

static	char	**ft_splitstr(char *s, int numwords, int *lenwords, char c)
{
	int		start;
	int		i;
	char	**ret;

	ret = malloc((numwords + 1) * sizeof(char *));
	if (ret == NULL)
		return (NULL);
	start = 0;
	i = 0;
	while (i < numwords)
	{
		while (s[start] == c)
			start++;
		ret[i] = ft_substr(s, start, lenwords[i]);
		if (ret[i] == NULL)
		{
			ft_free_result(ret, i);
			return (NULL);
		}
		start += lenwords[i];
		i++;
	}
	ret[i] = NULL;
	return (ret);
}

static	void	ft_lenwords(char *s, char c, int *lenwords)
{
	int		len;
	size_t	i;
	int		z;

	z = 0;
	i = 0;
	while (i < ft_strlen(s))
	{
		len = 0;
		while (s[i] != c && s[i] != '\0')
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			lenwords[z] = len;
			z++;
		}
		if (s[i] == c)
			i++;
	}
}

static	int	ft_numwords(char *s, char c)
{
	int	numwords;
	int	i;

	numwords = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			numwords++;
			while (s[i] != '\0' && s[i] != c)
				++i;
		}
		else
		{
			while (s[i] == c)
				i++;
		}
	}
	return (numwords);
}

char	**ft_split(const char *s, char c)
{
	int		numwords;
	int		*lenwords;
	char	**ret;

	numwords = ft_numwords((char *)s, c);
	lenwords = (int *)malloc(numwords * sizeof(int));
	if (!lenwords)
	{
		free(lenwords);
		return (NULL);
	}
	ft_lenwords((char *)s, c, lenwords);
	ret = ft_splitstr((char *)s, numwords, lenwords, c);
	free(lenwords);
	return (ret);
}
