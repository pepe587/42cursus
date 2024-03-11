/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:48:24 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/28 16:02:19 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_time(t_data *data)
{
	struct timeval	time;
	int				timestamp_in_ms;
	int				timestamp_in_ms_ac;

	timestamp_in_ms = data->start.tv_sec * 1000;
	timestamp_in_ms += data->start.tv_usec / 1000;
	gettimeofday(&time, NULL);
	timestamp_in_ms_ac = time.tv_sec * 1000;
	timestamp_in_ms_ac += time.tv_usec / 1000;
	return (timestamp_in_ms_ac - timestamp_in_ms);
}

int	init_data(t_data *data, int argc, char **argv)
{
	if (argc < 5)
		return (0);
	if (!is_all_num(argv[1]) || !is_all_num(argv[2])
		|| !is_all_num(argv[3]) || !is_all_num(argv[4]))
		return (0);
	data->is_alive = 1;
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->philos = malloc(sizeof(t_philo) * (data->num_of_philos + 1));
	if (!(data->philos))
		return (0);
	if (argc > 5)
	{
		if (!is_all_num(argv[5]))
			return (0);
		data->must_eat = ft_atoi(argv[5]);
	}
	else
		data->must_eat = -1;
	if (data->num_of_philos < 1 || data->time_to_die < 1
		|| data->time_to_eat < 1 || data->time_to_sleep < 1)
		return (0);
	return (1);
}

void	*routine(void *arg)
{
	t_data			*data;
	int				actual_philo;
	int				last_fork;

	data = arg;
	pthread_mutex_lock(&(data->mutex));
	actual_philo = data->actual_philo;
	last_fork = data->num_of_philos - 1;
	pthread_mutex_unlock(&(data->mutex));
	while (1)
	{
		if (!eat(data, actual_philo - 1, last_fork))
			return (NULL);
		if (!check_simulation_state(data, actual_philo, 0))
			return (NULL);
		philo_sleep(data, actual_philo - 1);
		if (!check_simulation_state(data, actual_philo, 0))
			return (NULL);
		think(data, actual_philo - 1);
	}
	return (NULL);
}

void	init_philos(int num_philos, t_data *data)
{
	int	i;

	pthread_mutex_init(&(data->mutex), NULL);
	i = 0;
	gettimeofday(&data->start, NULL);
	while (num_philos)
	{
		pthread_mutex_lock(&(data->mutex));
		data->philos[i].last_eat = time_in_ms();
		data->philos[i].philo_id = i + 1;
		data->philos[i].num_of_eats = 0;
		data->actual_philo = i + 1;
		pthread_mutex_init(&(data->philos[i].fork), NULL);
		pthread_create(&(data->philos[i].pths), NULL, routine, data);
		pthread_mutex_unlock(&(data->mutex));
		usleep(10);
		i++;
		num_philos--;
	}
}

int	main(int argc, char **argv)
{
	t_data			data;

	if (!init_data(&data, argc, argv))
		return (0);
	init_philos(ft_atoi(argv[1]), &data);
	pthread_create(&data.dead_check, NULL, dead_check, &data);
	pthread_join(data.dead_check, NULL);
	free_data(&data, ft_atoi(argv[1]) - 1);
}
