/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:20:25 by juliensarda       #+#    #+#             */
/*   Updated: 2024/03/27 12:01:18 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_threads(t_philo *philos)
{
    int i;
    int finished_eating;

    i = -1;
    while (++i < philos->num_of_philos)
	    safe_thread(&philos[i].thread, philo_routine, &philos[i], CREATE);
    finished_eating = 1;
    while (i <= philos->num_of_philos)
    {
        i--;
        if (check_death(&philos[i]) || (finished_eating == 1 && i == 0))
            break ;
        safe_mutex(&(philos->prog->meal_lock), LOCK);
        if (philos->num_times_to_eat <= 0 || philos[i].meal_eaten < philos[i].num_times_to_eat)
            finished_eating = 0;
        safe_mutex(&(philos->prog->meal_lock), UNLOCK);
        if (i == 0)
        {
            i = philos->num_of_philos;
            finished_eating = 1;
        }
    }
    i = -1;
    while (++i < philos->num_of_philos)
	   safe_thread(&philos[i].thread, NULL, NULL, JOIN);
}
