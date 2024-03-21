/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:09:01 by juliensarda       #+#    #+#             */
/*   Updated: 2024/03/21 09:46:50 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destory_all(t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&philo->printf_lock);
	pthread_mutex_destroy(&philo->meal_lock);
	while (i < philo->num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

int check_death(t_philo *philo)
{
   size_t last_meal_tmp;

    safe_mutex(&philo->meal_lock, LOCK);
    last_meal_tmp = philo->last_meal;
    safe_mutex(&philo->meal_lock, UNLOCK);
    if (get_time_of_day() -  last_meal_tmp >= (size_t)philo->time_to_die)
    {
        print_message(philo->id, "philo died", philo);
        philo->dead = 1;
        return (0);
    }
    return (1);
}