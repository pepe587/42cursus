/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:20:02 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/10 14:13:44 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi_long(const char *str)
{
	int			i;
	long long	num;
	int			neg;

	num = 0;
	neg = 1;
	i = 0;
	while (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-' || str[i + 1] == '+')
			return (0);
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * neg);
}

int	check_maxint(char **argv, int i)
{
	long long	num;

	while (argv[i])
	{
		num = ft_atoi_long(argv[i]);
		if (num > 2147483647 || num < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates_args(char **argv, int i)
{
	int	x;
	int	len;

	x = 0;
	while (argv[i + 1])
	{
		x = i + 1;
		while (argv[x])
		{
			if (ft_strlen(argv[i]) >= ft_strlen(argv[x]))
				len = ft_strlen(argv[i]);
			else
				len = ft_strlen(argv[x]);
			if (ft_strncmp_and_free(ft_itoa(ft_atoi_long(argv[i])),
					ft_itoa(ft_atoi_long(argv[x])), len) == 0)
				return (0);
			x++;
		}
		x = 0;
		i++;
	}
	return (1);
}

int	is_all_num(char **argv, int i)
{
	int	x;
	int	e;

	e = 0;
	x = 0;
	if (i == 0)
		e++;
	while (argv[i])
	{
		while (argv[i][x])
		{
			if (argv[i][x] == 32 && e == 0)
				return (2);
			if (ft_isdigit(argv[i][x]) == 0)
			{
				if (argv[i][x] == '-' && x == 0)
					break ;
				return (0);
			}
			x++;
		}
		x = 0;
		i++;
	}
	return (1);
}

int	check_errors(char **argv, int i)
{
	if (is_all_num(argv, i) == 0)
		return (0);
	if (check_duplicates_args(argv, i) == 0)
		return (0);
	if (check_maxint(argv, i) == 0)
		return (0);
	if (is_all_num(argv, i) == 2)
		return (2);
	return (1);
}
