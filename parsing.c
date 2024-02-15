/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:57:10 by jsarda            #+#    #+#             */
/*   Updated: 2024/02/15 10:15:45 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*args are :
1.number_of_philosophers
2.time_to_die
3.time_to_eat
4.time_to_sleep
5.number_of_times_each_philosopher_must_eat(optional)*/

/*function to skipp whitespaces*/
static t_bool	is_white_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (true);
	return (false);
}

/*function to check if its a digit or not*/
static t_bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

static void	is_valid(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '-')
			error_exit("You can only have Positive value !");
		if (!is_digit(str[i]) && !is_white_space((str[i])))
			error_exit("You can only have Digit !");
		i++;
	}
}

// i need to make an atol function tu change the string into numbers
static long	ft_atol(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	if (ft_strlen(str) > 10)
		error_exit("Cannot be a value bigger than INT_MAX !");
	is_valid(str);
	if (str[i] == '+')
		i++;
	while (is_digit(str[i]))
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	if (num > INT_MAX)
		error_exit("Cannot be a value bigger than INT_MAX !");
	return (num);
}

// parse and init my arguments
void	parsing_init(t_philo *philo, char **argv)
{
	philo->num_of_philos = ft_atol(argv[1]);
	if (philo->num_of_philos > PHILO_MAX)
		error_exit("Cannot have more than 200 philosophers !");
	philo->time_to_die = ft_atol(argv[2]);
	philo->time_to_eat = ft_atol(argv[3]);
	philo->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		philo->num_times_to_eat = ft_atol(argv[5]);
}
