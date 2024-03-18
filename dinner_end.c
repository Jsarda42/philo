/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:09:01 by juliensarda       #+#    #+#             */
/*   Updated: 2024/03/18 12:00:48 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *check_death(void *pointer)
{
    t_philo *philo = (t_philo *)pointer;
    if (get_time_of_day() - philo->last_meal >= (size_t)philo->time_to_die)
    {
        printf("philo died\n");
    }
    return (NULL);
}