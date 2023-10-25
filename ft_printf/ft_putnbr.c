/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atembras <atembras@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:25:47 by atembras          #+#    #+#             */
/*   Updated: 2023/10/19 21:06:11 by atembras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int		count;

	count = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		count += 11;
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		count++;
		count += ft_putnbr_fd(-n, fd);
	}
	else if (n < 10)
	{
		ft_putchar_fd(n + '0', fd);
		count++;
	}
	else
	{
		count += ft_putnbr_fd(n / 10, fd);
		count += ft_putnbr_fd(n % 10, fd);
	}
	return (count);
}
