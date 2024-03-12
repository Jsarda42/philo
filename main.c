/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:57 by jsarda            #+#    #+#             */
/*   Updated: 2024/03/11 17:32:36 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			philo[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];
	pthread_t threads[PHILO_MAX];

	if (argc != 5 && argc != 6)
		error_exit("The arguments must be 5 or 6");
	// 1. parsing
	parsing_init(philo, argc, argv);
	// 2.init data
	init_forks(forks, philo->num_of_philos);
	philo_init(philo, forks);
// 	// 3.dinner start
for (int i = 0; i < philo->num_of_philos; i++)
	safe_thread(&threads[i], philo_routine, &philo[i], CREATE);
	// opt 1
	// loop untill  they all die
	// then join
	// opt 2
	// detatch
	// loop until they all die
	// before exit make sure all threads have finished
for (int i = 0; i < philo->num_of_philos; i++)
	safe_thread(&threads[i], NULL, NULL, JOIN);
// 	// 4.dinner end clean table
	return (0);
}
