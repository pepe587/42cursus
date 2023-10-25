/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punt_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atembras <atembras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:38:29 by atembras          #+#    #+#             */
/*   Updated: 2023/10/19 21:05:49 by atembras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthexa(char *digits, unsigned int n)
{
	unsigned int	base;
	char			hex_digits;
	static int		ret = 0;

	base = 16;
	hex_digits = digits[n % base];
	if (n >= base)
		puthexa(digits, n / base);
	ret += ft_putchar(hex_digits);
	return (ret);
}

int	ft_punt_hexa(void *p)
{
	unsigned long long	pointer;
	int					l;

	l = 0;
	pointer = (unsigned long long)p;
	l += write (1, "0x", 2);
	l = puthexa("0123456789abcdef", pointer);
	return (l);
}
