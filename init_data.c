/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:57:42 by jsarda            #+#    #+#             */
/*   Updated: 2024/03/21 09:18:11 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_forks(pthread_mutex_t *forks, int philo_num)
{
	int	i;

	i = 0;
	while (philo_num > i)
	{
		safe_mutex(&forks[i], INIT);
		i++;
	}
}

void init_printf_lock(t_philo *philo)
{
		safe_mutex(&philo->printf_lock, INIT);
}

void init_meal_lock(t_philo *philo)
{
		safe_mutex(&philo->meal_lock, INIT);
}

void	philo_init(t_philo *philos, pthread_mutex_t	*forks)
{
	int	i;
	
	i = 0;
	philos->dead = 0;
	while (i < philos->num_of_philos)
	{
		philos[i].id = i + 1;
 		philos[i].eating = 0;
		philos[i].start_time = get_time_of_day();
		philos[i].philo_fork = &forks[i];
		philos[i].time_to_eat = philos[0].time_to_eat;
		philos[i].time_to_sleep = philos[0].time_to_sleep;
		philos[i].last_meal = philos[i].start_time;
		if (i == 0)
			philos[i].neighbor_fork = &forks[philos[i].num_of_philos - 1];
		else
			philos[i].neighbor_fork = &forks[i - 1];
		i++;
	}
}


