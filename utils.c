/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:08:09 by jsarda            #+#    #+#             */
/*   Updated: 2024/04/01 19:13:39 by jsarda           ###   ########.fr       */
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

void	wait_before_start(t_philo *philo)
{
	if (philo->num_of_philos == 1)
	{
		return ;
	}
	if (philo->id % 2 == 1)
	{
		print_message(philo->id, "is thinking", philo);
	}
	if (philo->id == philo->num_of_philos
		&& philo->num_of_philos % 2 == 1)
	{
		usleep(philo->time_to_eat * 2 * 1000);
	}
	else if (philo->id % 2 == 1 )
		usleep(philo->time_to_eat * 1000);
}

void	thinking_time(t_philo *philo)
{
	if (philo->num_of_philos % 2 == 0)
	{
		if ((philo->time_to_eat - philo->time_to_sleep) > 0)
		{
			usleep(((philo->time_to_eat) - philo->time_to_sleep) * 1000);
		}
	}
	else
	{
		if (((philo->time_to_eat * 2) - philo->time_to_sleep) > 0)
		{
			usleep(((philo->time_to_eat * 2) - philo->time_to_sleep) * 1000);
		}
	}
}

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
