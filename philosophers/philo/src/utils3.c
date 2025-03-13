/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:37:07 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/28 16:06:25 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	are_satiated(t_data *data)
{
	int	i;

	i = 0;
	if (data->must_eat == -1)
		return (0);
	while (i < data->num_of_philos)
	{
		if (data->philos[i].num_of_eats < data->must_eat)
			return (0);
		i++;
	}
	return (1);
}

void	*dead_check(void *arg)
{
	t_data	*data;
	int		num_of_philos;
	int		aux;

	data = arg;
	pthread_mutex_lock(&(data->mutex));
	num_of_philos = data->num_of_philos - 1;
	pthread_mutex_unlock(&(data->mutex));
	while (1)
	{
		pthread_mutex_lock(&(data->mutex));
		if (!data->is_alive)
			return (NULL);
		pthread_mutex_unlock(&(data->mutex));
		aux = num_of_philos;
		while (aux >= 0)
		{
			if (!check_simulation_state(data, aux + 1, 0))
				return (NULL);
			aux--;
		}
	}
	return (NULL);
}

long	time_in_ms(void)
{
	struct timeval	init;
	long			result;

	gettimeofday(&init, NULL);
	result = init.tv_sec * 1000;
	result += init.tv_usec / 1000;
	return (result);
}

void	sleep_2(int time)
{
	struct timeval	st;
	struct timeval	aux;
	long			start;
	long			cmp;

	gettimeofday(&st, NULL);
	gettimeofday(&aux, NULL);
	start = st.tv_sec * 1000;
	start += st.tv_usec / 1000;
	cmp = aux.tv_sec * 1000;
	cmp += aux.tv_usec / 1000;
	while ((cmp - start) < time)
	{
		gettimeofday(&aux, NULL);
		cmp = aux.tv_sec * 1000;
		cmp += aux.tv_usec / 1000;
	}
}

int	eat_2(t_data *data, int ap, int last_fork)
{
	if ((data->is_alive) && data->must_eat != 0)
	{
		if (!check_simulation_state(data, ap + 1, 1))
			return (0);
		printf("%d %d is eating\n", get_time(data), data->philos[ap].philo_id);
		sleep_2(data->time_to_eat);
	}
	if (ap != 0)
	{
		pthread_mutex_unlock(&(data->philos[ap].fork));
		pthread_mutex_unlock(&(data->philos[ap - 1].fork));
	}
	else
	{
		pthread_mutex_unlock(&(data->philos[ap].fork));
		pthread_mutex_unlock(&(data->philos[last_fork].fork));
	}
	return (1);
}
