/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:57 by jsarda            #+#    #+#             */
/*   Updated: 2024/02/16 14:30:15 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	main(int argc, char **argv)
// {
// 	t_philo		philo[PHILO_MAX];
// 	pthread_mutex_t	forks[PHILO_MAX];

// 	if (argc != 5 && argc != 6)
// 		error_exit("The arguments must be 5 or 6");
// 	// 1. parsing
// 	parsing_init(philo, argv);
// 	// 2.init data
// 	init_forks(forks, philo->num_of_philos);
// 	philo_init(philo, forks);
// 	// 3.dinner start

// 	while (42){

// 	}
// 	// 4.dinner end clean table
// 	return (0);
// }

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

long int start;

void * routine (void *ptr) {
	int i = 0;
	while (i < 1000) {
		usleep(50);
		i++;
	}
	printf("%d [%lu]\n", *((int *)ptr), get_time_of_day() - start);
	routine(ptr);
	return (ptr);
}

int	main(int argc, char **argv)
{
	int i;
	int philo_id[5];
	pthread_t threads[5];

	i = 0;
	start = get_time_of_day();
	while (i < 5) {
		philo_id[i] = i + 1;
		pthread_create(&threads[i], NULL, routine, philo_id + i);
		i++;
	}
	i = 0;
	while (i < 5) {
		pthread_join(threads[i], NULL);
		i++;
	}



	return (0);
}
