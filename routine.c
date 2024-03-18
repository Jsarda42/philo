/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:41:33 by jsarda            #+#    #+#             */
/*   Updated: 2024/03/18 10:45:56 by juliensarda      ###   ########.fr       */
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
	write(1, "hello\n", 6);
	if (philo->num_of_philos == 1)
	{
		// if there if 1 philo i let him take his fork
		// i make him sleep the time of death because there is no other fork
		// and i unlock his fork
		usleep_breakdown(philo->time_to_die);
		// here i still need to trigger something so my program now his last meal lasted
		// the time of the time of death 
		// probably philo->last_meal = time_of_death
		philo->last_meal = philo->time_to_die;
		// it seems to work but the message would print before the usleep finish
		safe_mutex(philo->philo_fork, UNLOCK);
		return ;
	}
	if (philo->id % 2 == 0)
		safe_mutex(philo->philo_fork, LOCK);
	else
		safe_mutex(philo->neighbor_fork, LOCK);
	print_message(philo->id, "has taken a fork", philo);
    print_message(philo->id, "is eating", philo);
	philo->last_meal = get_time_of_day();
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
	while (42)
	{
		eating_routine(philo);
		sleeping_routine(philo);
		print_message(philo->id, "is thinking", philo);
	}
	return (NULL);
}