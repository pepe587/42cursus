/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:36:07 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/19 16:31:25 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	char	*ft_ret0(char *str)
{
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static	int	ft_intsize(int long long n)
{
	int	len;

	len = 1;
	if (n == 0)
		return (2);
	if (n < 0)
	{
		len++;
		n = n * -1;
	}
	while (n >= 1)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static	char	*ft_strrev(char *str, int num)
{
	size_t	i;
	size_t	rev;
	int		aux;

	str[num] = '\0';
	aux = 0;
	i = 0;
	rev = num - 1;
	while (rev > i)
	{
		aux = str[rev];
		str[rev] = str[i];
		str[i] = aux;
		rev--;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	i;
	int		sign;

	if (n < 0)
		sign = -1;
	else
		sign = 1;
	i = 0;
	ret = (char *)malloc(ft_intsize(n) * sizeof(char));
	if (ret == NULL)
		return (0);
	if (n == 0)
		return (ft_ret0(ret));
	else
	{
		while (n != 0)
		{
			ret[i++] = (sign * (n % 10)) + '0';
			n = n / 10;
		}
		if (sign == -1)
			ret[i++] = '-';
	}
	return (ft_strrev(ret, i));
}
