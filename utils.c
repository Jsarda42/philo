/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:08:09 by jsarda            #+#    #+#             */
/*   Updated: 2024/03/29 12:29:37 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	error_exit(const char *error)
{
	printf(RED "🚨 %s 🚨\n" RST, error);
	exit(EXIT_FAILURE);
}

void	usleep_breakdown(size_t time_ms)
{
	ssize_t	time_us;

	time_us = time_ms * 1000;
	usleep(time_us);
}

// void	usleep_breakdown(size_t time_ms)
// {
// 	size_t	start;

// 	start = get_time_of_day();
// 	while ((get_time_of_day() - start) < time_ms)
// 		usleep(500);
// }

size_t	get_time_of_day(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		error_exit("Erreur getting the time");
	return ((current_time.tv_sec * 1000) + current_time.tv_usec / 1000);
}

void	print_message(int id, char *message, t_philo *philo)
{
	size_t	time;

	if (!is_philo_dead(philo))
	{
		safe_mutex(&philo->prog->printf_lock, LOCK);
		time = get_time_of_day() - philo->start_time;
		printf("%zu %d %s\n", time, id, message);
		safe_mutex(&philo->prog->printf_lock, UNLOCK);
	}
}
