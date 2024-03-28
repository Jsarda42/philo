/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:09:01 by juliensarda       #+#    #+#             */
/*   Updated: 2024/03/28 11:19:39 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destory_all(t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	safe_mutex(&philo->prog->printf_lock, DESTROY);
	safe_mutex(&philo->prog->meal_lock, DESTROY);
	safe_mutex(&philo->prog->dead_lock, DESTROY);
	while (i < philo->num_of_philos)
	{
		safe_mutex(&forks[i], DESTROY);
		i++;
	}
}

int	check_death(t_philo *philo)
{
	size_t	last_meal_tmp;

	safe_mutex(&philo->prog->meal_lock, LOCK);
	last_meal_tmp = philo->last_meal;
	safe_mutex(&philo->prog->meal_lock, UNLOCK);
	if (get_time_of_day() - last_meal_tmp >= (size_t)philo->time_to_die)
	{
		print_message(philo->id, "died", philo);
		safe_mutex(&philo->prog->dead_lock, LOCK);
		philo->prog->dead_flag = 1;
		safe_mutex(&philo->prog->dead_lock, UNLOCK);
		return (1);
	}
	return (0);
}
