/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:20:25 by juliensarda       #+#    #+#             */
/*   Updated: 2024/03/26 14:54:53 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_threads(t_philo *philos)
{
    int i;

    i = 0;
    while (i < philos->num_of_philos)
    {
	    safe_thread(&philos[i].thread, philo_routine, &philos[i], CREATE);
        i++;
    }
    // i = 0;
    // while (i < philos->num_of_philos)
    // {
    //     if(check_death(&philos[i]) == 0)
    //         break ;
    //     i++;
    // }
    // i = -1;
    // while (++i < philos->num_of_philos)
    // {
    //     safe_mutex(philos[i].dead_lock, LOCK);
    //     // philos[i].dead;
    //     safe_mutex(philos[i].dead_lock, UNLOCK);
    // }
    i = -1;
    while (++i < philos->num_of_philos)
	   safe_thread(&philos[i].thread, NULL, NULL, JOIN);
}
