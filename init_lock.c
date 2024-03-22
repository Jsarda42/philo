/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:38:10 by juliensarda       #+#    #+#             */
/*   Updated: 2024/03/22 13:09:55 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void init_printf_lock(t_philo *philo)
{
		safe_mutex(&philo->printf_lock, INIT);
}

void init_dead_lock(t_philo *philo)
{
		safe_mutex(&philo->dead_lock, INIT);
}

void init_meal_lock(t_philo *philo)
{
		safe_mutex(&philo->meal_lock, INIT);
}

void init_lock(t_philo *philo)
{
	init_meal_lock(philo);
	init_dead_lock(philo);
	init_printf_lock(philo);
}