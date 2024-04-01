/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:20:25 by juliensarda       #+#    #+#             */
/*   Updated: 2024/04/01 20:53:41 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	check_death(t_philo *philo)
{
	size_t	last_meal_tmp;

	safe_mutex(&philo->prog->meal_lock, LOCK);
	last_meal_tmp = philo->last_meal;
	safe_mutex(&philo->prog->meal_lock, UNLOCK);
	if (get_time_of_day() - last_meal_tmp >= (size_t)philo->time_to_die)
	{
		print_message(philo->id, "died", philo);
		safe_mutex(&philo->prog->dead_lock, LOCK);
		philo->prog->dead_flag = 1;
		safe_mutex(&philo->prog->dead_lock, UNLOCK);
		return (1);
	}
	return (0);
}

int	check_death_for_each_philo(t_philo *philo)
{
	int i;
	i= 0;
	while (i < philo->num_of_philos)
	{
		if (check_death(&philo[i]))
			return (1);
		i++;
	}
	return (0);
}


void	*check_status(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *)pointer;
	while (1)
		if (check_death_for_each_philo(philos) == 1)
			break ;
	return (pointer);
}

void	ft_threads(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos->num_of_philos)
		safe_thread(&philos[i].thread, philo_routine, &philos[i], CREATE);
	i = -1;
	while (++i < philos->num_of_philos)
		safe_thread(&philos[i].thread, check_status, &philos[i], CREATE);
	i = 0;
	while (i < philos->num_of_philos)
		safe_thread(&philos[i++].thread, NULL, NULL, JOIN);
}
