/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:57 by jsarda            #+#    #+#             */
/*   Updated: 2024/02/19 15:50:16 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			philo[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];
	t_program		program;

	if (argc != 5 && argc != 6)
		error_exit("The arguments must be 5 or 6");
	// 1. parsing
	parsing_init(philo, argv);
	// 2.init data
	init_forks(forks, philo->num_of_philos);
	philo_init(philo, forks, program);
	// 3.dinner start
	// 4.dinner end clean table
	return (0);
}

// int				meals = 0;
// pthread_mutex_t	mutex;

// void	*philo_eating(void *foo)
// {
// 	long	i;

// 	i = 0;
// 	while (i < 1000)
// 	{
// 		pthread_mutex_lock(&mutex);
// 		meals++;
// 		i++;
// 		pthread_mutex_unlock(&mutex);
// 	}
// 	return (NULL);
// }

// long int start;

// void * routine (void *ptr) {
// 	int i = 0;
// 	while (i < 1000) {
// 		usleep(50);
// 		i++;
// 	}
// 	printf("%d [%lu]\n", *((int *)ptr), get_time_of_day() - start);
// 	routine(ptr);
// 	return (ptr);
// }
