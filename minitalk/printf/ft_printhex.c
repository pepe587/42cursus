/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:55:11 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/07/17 17:51:28 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static void	dectohex(unsigned long long dec, int mayus)
{
	if (dec >= 16)
	{
		dectohex(dec / 16, mayus);
		dectohex(dec % 16, mayus);
	}
	else
	{
		if (dec <= 9)
			ft_putchar_fd(dec + 48, 1);
		else
		{
			if (mayus == 1)
				ft_putchar_fd(dec + 55, 1);
			else
				ft_putchar_fd(dec + 87, 1);
		}
	}
}

int	ft_hexlen(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_printhex(unsigned int num, int mayus)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		dectohex(num, mayus);
	return (ft_hexlen(num));
}
