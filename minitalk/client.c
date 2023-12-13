/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:53:37 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/11 20:44:26 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void	ft_send_message(int PID, char *message)
{
	int	bit;
	int	i;

	i = 0;
	while (message[i])
	{
		bit = 7;
		while (bit >= 0)
		{
			if (message[i] & (1 << bit))
				kill(PID, SIGUSR2);
			else
				kill(PID, SIGUSR1);
			bit--;
			usleep(25);
		}
		i++;
	}
}

int	check_errors(int argc, char **argv)
{
	int	x;

	x = -1;
	if (argc != 3)
		return (ft_printf("Error with the arguments\n"), 0);
	while (argv[1][x++ + 1])
		if (!ft_isdigit(argv[1][x]))
			return (ft_printf("Error, invalid PID\n"), 0);
	if (*argv[2] == 0)
		return (ft_printf("The message is empty\n"), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	if (!check_errors(argc, argv))
		return (0);
	ft_send_message(ft_atoi((const char *)argv[1]), argv[2]);
}
