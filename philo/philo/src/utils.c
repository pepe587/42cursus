/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:08:27 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/28 16:05:46 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	think(t_data *data, int ap)
{
	pthread_mutex_lock(&(data->mutex));
	if (data->is_alive)
		printf("%d %d num is thinking\n",
			get_time(data), data->philos[ap].philo_id);
	pthread_mutex_unlock(&(data->mutex));
	return (1);
}

int	philo_sleep(t_data *data, int ap)
{
	int	sleep_time;

	pthread_mutex_lock(&(data->mutex));
	sleep_time = data->time_to_sleep;
	if (data->is_alive)
		printf("%d %d num is sleeping\n", get_time(data),
			data->philos[ap].philo_id);
	pthread_mutex_unlock(&(data->mutex));
	sleep_2(sleep_time);
	return (1);
}

int	eat(t_data *data, int ap, int last_fork)
{
	if (!check_simulation_state(data, ap + 1, 0))
		return (0);
	if (ap != 0)
	{
		pthread_mutex_lock(&(data->philos[ap - 1].fork));
		printf("%d %d has taken a fork\n", get_time(data),
			data->philos[ap].philo_id);
		pthread_mutex_lock(&(data->philos[ap].fork));
		printf("%d %d has taken a fork\n", get_time(data),
			data->philos[ap].philo_id);
	}
	else
	{
		pthread_mutex_lock(&(data->philos[last_fork].fork));
		printf("%d %d has taken a fork\n", get_time(data),
			data->philos[ap].philo_id);
		pthread_mutex_lock(&(data->philos[ap].fork));
		printf("%d %d has taken a fork\n", get_time(data),
			data->philos[ap].philo_id);
	}
	if (!eat_2(data, ap, last_fork))
		return (0);
	return (increment_eat(data, ap), 1);
}

void	free_pths(pthread_t *pths, int num_philos)
{
	int	i;

	i = 0;
	while (num_philos--)
	{
		free(pths + i);
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	num;
	int	i;
	int	neg;

	i = 0;
	num = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i])
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * neg);
}
