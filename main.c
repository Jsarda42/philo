/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:58:57 by jsarda            #+#    #+#             */
/*   Updated: 2024/02/12 08:22:36 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	/*number or arguments 5 or 6*/
	if (argc == 5 || argc == 6)
	{
		//1. parsing
		parsing();
		//2.init data
		//3.dinner start
		//4.dinner end clean table
	}
	/*otherwise we need error message*/
	else
		error_message();
	return (0);
}
