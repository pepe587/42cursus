/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jose-mgo <jose-mgo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:49:54 by jose-mgo          #+#    #+#             */
/*   Updated: 2024/02/28 16:06:31 by jose-mgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int					philo_id;
	pthread_t			pths;
	pthread_mutex_t		fork;
	long				last_eat;
	int					num_of_eats;
}	t_philo;

typedef struct s_data
{
	int				actual_philo;
	int				time_to_sleep;
	int				time_to_die;
	int				time_to_eat;
	int				num_of_philos;
	int				must_eat;
	int				is_alive;
	t_philo			*philos;
	pthread_mutex_t	mutex;
	struct timeval	start;
	pthread_t		dead_check;
}	t_data;

int		ft_atoi(char *str);
void	free_pths(pthread_t *pths, int num_philos);
int		think(t_data *data, int ap);
int		philo_sleep(t_data *data, int ap);
int		eat(t_data *data, int ap, int last_fork);
void	increment_eat(t_data *data, int actual_philo);
void	free_data(t_data *data, int philos);
int		get_time(t_data *data);
int		must_dead(t_data *data, int ap, int boolean);
int		check_simulation_state(t_data *data, int actual_philo, int boolean);
int		is_all_num(char *str);
int		are_satiated(t_data *data);
void	*dead_check(void *arg);
long	time_in_ms(void);
void	sleep_2(int time);
int		eat_2(t_data *data, int ap, int last_fork);

#endif