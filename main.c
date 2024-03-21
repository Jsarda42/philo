/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:57 by jsarda            #+#    #+#             */
/*   Updated: 2024/03/21 11:33:44 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_philo			philo[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];
	pthread_t threads[PHILO_MAX + 1];
	
	if (argc != 5 && argc != 6)
		error_exit("The arguments must be 5 or 6");
	parsing_init(philo, argc, argv);
	philo_init(philo, forks);
	ft_threads(philo, threads);
	destory_all(philo, forks);
	return (0);
}
