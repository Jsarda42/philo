/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:57:42 by jsarda            #+#    #+#             */
/*   Updated: 2024/02/14 14:02:38 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*the function to define forks will define one fork on the left for
each philo so the right fork will be the fork of the philo on the right of the
actual philo
ex : philo 1 left fork id 1 right fork id 5
	 philo 2 left fork id 2 right fork id 1
	 philo 3 left fork id 3 right fork id 2
	 philo 4 left fork id 4 right fork id 3
	 philo 5 left fork id 5 right fork id 4*/

static void	philo_init(t_table *table)
{
	int i;
	t_philo *philo;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_count = 0;
		// i need my forks
		printf("philo id : %d\n", philo->id);
		i++;
	}
}

void	data_init(t_table *table)
{
	table->philos = safe_malloc(table->philo_nbr * sizeof(t_philo));
	philo_init(table);
}
