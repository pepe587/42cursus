/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 14:10:58 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/26 13:49:10 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>
#include "ft_printf.h"

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

int	ft_format2(const char *str, int i, int len, va_list args)
{
	unsigned long	ptr;
	int				dec;

	if (str[i + 1] == 'p')
	{
		ptr = va_arg(args, unsigned long);
		write(1, "0", 1);
		write(1, "x", 1);
		len += dectohex(ptr, 0) + 2;
	}
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
	{
		dec = va_arg(args, int);
		ft_putnbr_fd(dec, 1);
		len += ft_intsize(dec);
	}
	else
		len = ft_format3(str, i, len, args);
	return (len);
}
