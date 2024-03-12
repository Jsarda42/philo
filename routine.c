/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:41:33 by jsarda            #+#    #+#             */
/*   Updated: 2024/03/11 17:53:25 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//1.eating
void	eating_routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		safe_mutex(philo->neighbor_fork, LOCK); // lock the right fork
	else
		safe_mutex(philo->philo_fork, LOCK); // lock the left fork
	print_message(philo->id, "has taken a fork", philo);
	if (philo->id % 2 == 0)
		safe_mutex(philo->philo_fork, LOCK); // lock the right fork
	else
		safe_mutex(philo->neighbor_fork, LOCK); // lock the left fork
	print_message(philo->id, "has taken a fork", philo);
    philo->eating = 1;
    print_message(philo->id, "is eating", philo);
    usleep_breakdown(philo->time_to_eat);
    philo->eating = 0;
	safe_mutex(philo->neighbor_fork, UNLOCK);
	safe_mutex(philo->philo_fork, UNLOCK);
}

void	*philo_routine(void *pointer)
{
	t_philo *philo = (t_philo *)pointer;
	if (!philo)
		return (NULL);
	while (!philo->dead)
	{
		eating_routine(philo);
   		print_message(philo->id, "is sleeping", philo);
		usleep_breakdown(philo->time_to_sleep);
		print_message(philo->id, "is thinking", philo);
	}
	return (NULL);
}