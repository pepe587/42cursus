/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:31:24 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/27 19:40:26 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	must_dead(t_data *data, int ap, int boolean)
{
	struct timeval				actual_eat;
	long						timestamp_actual_eat;
	int							ret;
	long						time_since_last_eat;

	gettimeofday(&actual_eat, NULL);
	timestamp_actual_eat = actual_eat.tv_sec * 1000;
	timestamp_actual_eat += actual_eat.tv_usec / 1000;
	time_since_last_eat = timestamp_actual_eat - data->philos[ap].last_eat;
	ret = time_since_last_eat > data->time_to_die;
	if (boolean == 1)
		data->philos[ap].last_eat = timestamp_actual_eat;
	return (ret);
}

void	free_data(t_data *data, int philos)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&(data->mutex));
	while (i < philos)
	{
		pthread_mutex_destroy(&(data->philos[i].fork));
		i++;
	}
	free(data->philos);
}

int	is_all_num(char *str)
{
	while (*str)
	{
		if (*str > '9' || *str < '0')
			return (0);
		str++;
	}
	return (1);
}

void	increment_eat(t_data *data, int actual_philo)
{
	pthread_mutex_lock(&(data->mutex));
	if (data->must_eat > 0)
		data->philos[actual_philo].num_of_eats++;
	pthread_mutex_unlock(&(data->mutex));
}

int	check_simulation_state(t_data *data, int actual_philo, int boolean)
{
	pthread_mutex_lock(&(data->mutex));
	if ((are_satiated(data)) == 1 || data->is_alive == 0)
		return (pthread_mutex_unlock(&(data->mutex)), 0);
	if (must_dead(data, actual_philo - 1, boolean) == 1
		&& data->must_eat == -1 && data->is_alive)
	{
		data->is_alive = 0;
		return (printf("%d %d has died\n", get_time(data), actual_philo),
			pthread_mutex_unlock(&(data->mutex)), 0);
	}
	return (pthread_mutex_unlock(&(data->mutex)), 1);
}
