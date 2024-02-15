/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:57:42 by jsarda            #+#    #+#             */
/*   Updated: 2024/02/15 14:38:12 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*the function to define forks will define one fork on the left for
each philo so the right fork will be the fork of the philo on the right of the
actual philo
ex : philo 1 left fork id 1 right fork id 5
		philo 2 left fork id 2 right fork id 1
		philo 3 left fork id 3 right fork id 2
		philo 4 left fork id 4 right fork id 3
		philo 5 left fork id 5 right fork id 4*/

void	philo_init(t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < philo->num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].meals_eaten = 0;
		philo[i].start_time = get_time_of_day();
		philo[i].last_meal = get_time_of_day();
		philo[i].l_fork = &forks[i];
		i++;
	}
}
