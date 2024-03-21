/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:20:25 by juliensarda       #+#    #+#             */
/*   Updated: 2024/03/21 11:03:08 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_threads(t_philo *philo, pthread_t *threads)
{
    int i;

    i = 0;
    while (i < philo->num_of_philos)
    {
	    safe_thread(&threads[i], philo_routine, &philo[i], CREATE);
        i++;
    }
    while (check_death(philo))
        ;
    i = 0;
    while (i < philo->num_of_philos)
    {
        safe_mutex(&philo->dead_lock, LOCK);
        philo[i].dead = 1;
        safe_mutex(&philo->dead_lock, UNLOCK);
        i++;
    }
    i = 0;
    while (i < philo->num_of_philos)
    {
	   safe_thread(&threads[i], NULL, NULL, JOIN);
        i++;
    }
}