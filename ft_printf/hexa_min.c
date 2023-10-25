/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atembras <atembras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:58:01 by atembras          #+#    #+#             */
/*   Updated: 2023/10/19 21:06:33 by atembras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	puthexa(char *digits, unsigned int n)
{
	unsigned int	base;
	char			hex_digits;

	base = 16;
	hex_digits = digits[n % base];
	if (n >= base)
		puthexa(digits, n / base);
	ft_putchar(hex_digits);
}

int	hexa_min(int n)
{
	char			*hex_digits;
	unsigned int	u;

	hex_digits = "0123456789abcdef";
	if (n < 0)
	{
		u = (unsigned int)(-n);
		puthexa(hex_digits, u);
	}
	else
		puthexa(hex_digits, n);
	return (0);
}
