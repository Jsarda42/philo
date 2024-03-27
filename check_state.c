/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 08:40:54 by juliensarda       #+#    #+#             */
/*   Updated: 2024/03/27 11:28:55 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_dead(t_philo *philo)
{
	safe_mutex(&philo->prog->dead_lock, LOCK);
	if(philo->prog->dead_flag == 1)
	{
		safe_mutex(&philo->prog->dead_lock, UNLOCK);
		return (1);
	}
	safe_mutex(&philo->prog->dead_lock, UNLOCK);
	return (0);
}
