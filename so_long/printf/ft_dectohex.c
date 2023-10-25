/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dectohex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:31:24 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/29 13:55:53 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	ft_strupper(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 102)
			str[i] -= 32;
		i++;
	}
}

static	void	ft_strrev(char *str, int num)
{
	int		i;
	int		rev;
	int		aux;

	if (!str)
		return ;
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
}

int	dectohex(unsigned long long dec, int mayus)
{
	char	*tablehex;
	int		rest;
	char	tabledec[100];
	int		i;

	i = 0;
	rest = 0;
	tablehex = "0123456789abcdef";
	if (dec == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (dec != 0)
	{
		rest = dec % 16;
		tabledec[i] = tablehex[rest];
		dec /= 16;
		i++;
	}
	ft_strrev(tabledec, i);
	if (mayus == 1)
		ft_strupper(tabledec);
	ft_putstr_fd(tabledec, 1);
	return (ft_strlen(tabledec));
}
