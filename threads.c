/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:20:25 by juliensarda       #+#    #+#             */
/*   Updated: 2024/03/16 10:45:43 by juliensarda      ###   ########.fr       */
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
    //printf("time of death in threads function : %ld\n",philo->time_to_die);
    // i am getting the time of death in threads function
    // because i didnt get it in the cheack death function i replaced &philo[i]
    // by philo
    safe_thread(&threads[i], check_death, philo, CREATE);
    i = 0;
    while (i < philo->num_of_philos)
    {
	    safe_thread(&threads[i], NULL, NULL, JOIN);
        i++;
    }
}