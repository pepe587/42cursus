/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 20:13:40 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/05/26 13:49:04 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int	ft_format(const char *str, int i, int len, va_list args)
{
	char	c;
	char	*str2;

	if (str[i + 1] == '%')
	{
		write(1, "%%", 1);
		len += 1;
	}
	else if (str[i + 1] == 'c')
	{
		c = va_arg(args, int);
		write(1, &c, 1);
		len += 1;
	}
	else if (str[i + 1] == 's')
	{
		str2 = va_arg(args, char *);
		if (!str2)
			str2 = "(null)";
		ft_putstr_fd(str2, 1);
		len += ft_strlen(str2);
	}
	else
		len = ft_format2(str, i, len, args);
	return (len);
}
