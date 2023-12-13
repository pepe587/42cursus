/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:00:10 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/11/23 16:26:17 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

#include <unistd.h>

static	int	ft_intsize(int long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
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

int	ft_format3(const char *str, int i, int len, va_list args)
{
	long long		num;
	unsigned int	uns;

	uns = 0;
	if (str[i + 1] == 'u')
	{
		num = va_arg(args, long long);
		if (num < 0)
			uns = 4294967296 + num;
		else if (num >= 0)
			uns = (unsigned int)num;
		ft_putunbr_fd(uns, 1);
		len += ft_intsize(uns);
	}
	else if (str[i + 1] == 'x' || str[i + 1] == 'X')
	{
		if (str[i + 1] == 'X')
			uns = 1;
		num = va_arg(args, long long);
		len += ft_printhex(num, uns);
	}
	return (len);
}
