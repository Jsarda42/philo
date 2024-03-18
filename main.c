/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:57 by jsarda            #+#    #+#             */
/*   Updated: 2024/03/18 10:48:33 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>
int	main(int argc, char **argv)
{
	t_philo			philo[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];
	pthread_mutex_t	printf_lock[PHILO_MAX];
	pthread_t threads[PHILO_MAX + 1];
	
	if (argc != 5 && argc != 6)
		error_exit("The arguments must be 5 or 6");
	parsing_init(philo, argc, argv);
	init_forks(forks, philo->num_of_philos);
	init_printf_lock(printf_lock, philo->num_of_philos);
	philo_init(philo, forks, printf_lock);
	//printf("time of death from main : %ld\n", philo->time_to_die);
	// i am getting the time of death from main 
	ft_threads(philo, threads);
	return (0);
}
