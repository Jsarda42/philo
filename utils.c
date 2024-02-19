/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:08:09 by jsarda            #+#    #+#             */
/*   Updated: 2024/02/16 13:34:16 by jsarda           ###   ########.fr       */
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

size_t	get_time_of_day(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		error_exit("Erreur getting the time");
	return ((current_time.tv_sec * 1000) + current_time.tv_usec);
}
