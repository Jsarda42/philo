/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:09:01 by juliensarda       #+#    #+#             */
/*   Updated: 2024/03/17 18:21:56 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *check_death(void *pointer)
{
    t_philo *philo = (t_philo *)pointer;
    // i m getting the time of death 
    // now the idea is to compare the time of death with
    // the time my philo slept in the function routine
    // or the time the philo took to eat
    if (get_time_of_day() - philo->last_meal >= (size_t)philo->time_to_die)
    {
        // printf("this is time of day: %ld\n", get_time_of_day());
        // printf("this is last meal : %ld\n", philo->last_meal);
        // printf("this is time to die : %ld\n", philo->time_to_die);
        printf("philo died\n");
    }
    return (NULL);
}