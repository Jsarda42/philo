/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:57:42 by jsarda            #+#    #+#             */
/*   Updated: 2024/02/14 13:18:21 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_init(t_table *table)
{
	/*what do i need to init inside of my structure philo
	1. the id
	2. his fork
	3. */
}

void	data_init(t_table *table)
{
	table->philos = safe_malloc(sizeof(t_philo) * table->philo_nbr);
	philo_init();
}
