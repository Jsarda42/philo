/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:57 by jsarda            #+#    #+#             */
/*   Updated: 2024/02/15 14:56:25 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo		philo[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		error_exit("The arguments must be 5 or 6");
	// 1. parsing
	parsing_init(philo, argv);
	// 2.init data
	philo_init(philo, forks);
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

// int	main(int argc, char **argv)
// {
// 	t_philo		philo[PHILO_MAX];
// 	pthread_mutex_t	forks[PHILO_MAX];
// 	pthread_t	eating[8];
// 	int			i;

// 	i = 0;
// 	pthread_mutex_init(&mutex, NULL);
// 	if (argc != 5 && argc != 6)
// 		error_exit("The arguments must be 5 or 6");
// 	// 1. parsing
// 	parsing_init(philo, argv);
// 	// 2.init data
// 	philo_init(philo, forks);
// 	// 3.dinner start
// 	// 4.dinner end clean table
// 	while (i < 8)
// 	{
// 		safe_thread(&eating[i], &philo_eating, NULL, CREATE);
// 		printf("starting %d\n", i);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 8)
// 	{
// 		safe_thread(&eating[i], &philo_eating, NULL, JOIN);
// 		printf("finish %d\n", i);
// 		i++;
// 	}
// 	pthread_mutex_destroy(&mutex);
// 	printf("Numbers of meals %d\n", meals);
// 	return (0);
// }
