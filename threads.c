/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:20:25 by juliensarda       #+#    #+#             */
/*   Updated: 2024/03/18 16:24:44 by juliensarda      ###   ########.fr       */
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
    i = 0;
    while (check_death(philo))
        ;
    // Any one died now end all threads
    // loop all philos and set to died
    i = 0;
    while (i < philo->num_of_philos)
    {
        philo[i].dead = 1;
        i++;
    }
    i = 0;
    while (i < philo->num_of_philos)
    {
	   safe_thread(&threads[i], NULL, NULL, JOIN);
        i++;
    }
}