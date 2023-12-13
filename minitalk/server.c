/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:22:46 by jose-mgo          #+#    #+#             */
/*   Updated: 2023/12/11 13:59:16 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include "libft/libft.h"

void	ft_translate(int sig)
{
	static int	character = 0b00000000;
	static int	bit = 8;
	int			valuebit;

	valuebit = 0b0;
	if (sig == SIGUSR2)
	{
		valuebit = 1 << bit;
		character += valuebit;
	}
	bit--;
	if (bit == 0)
	{
		character = character >> 1;
		write(1, &character, 1);
		bit = 8;
		character = 0b00000000;
	}
}

int	main(void)
{
	printf("%d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_translate);
		signal(SIGUSR2, ft_translate);
		pause();
	}
}
