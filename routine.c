/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:41:33 by jsarda            #+#    #+#             */
/*   Updated: 2024/03/26 14:42:56 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
	 	safe_mutex(philo->neighbor_fork, LOCK);
	else
	 	safe_mutex(philo->philo_fork, LOCK);
	print_message(philo->id, "has taken a fork", philo);
	if (philo->id % 2 == 0)
	 	safe_mutex(philo->philo_fork, LOCK);
	else
	 	safe_mutex(philo->neighbor_fork, LOCK);
	print_message(philo->id, "has taken a fork", philo);
	
	safe_mutex(philo->meal_lock, LOCK);
	philo->last_meal = get_time_of_day();
	safe_mutex(philo->meal_lock, UNLOCK);

	
    print_message(philo->id, "is eating", philo);
    usleep_breakdown(philo->time_to_eat);
	
	safe_mutex(philo->neighbor_fork, UNLOCK);
	safe_mutex(philo->philo_fork, UNLOCK);
}

void	sleeping_routine(t_philo *philo)
{
	   	print_message(philo->id, "is sleeping", philo);
		usleep_breakdown(philo->time_to_sleep);
}

void	*philo_routine(void *pointer)
{
	t_philo *philo = (t_philo *)pointer;
	
	if (!philo)
		return (NULL);
	eating_routine(philo);
	sleeping_routine(philo);
	print_message(philo->id, "is thinking", philo);
	return (NULL);
}
