/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 13:41:33 by jsarda            #+#    #+#             */
/*   Updated: 2024/02/19 15:53:39 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*my thread of 1 philo
1.eating
2.sleeping
*/
void	*routine(void *ptr)
{
	struct philo *philo = (struct philo *)ptr;
	//3 100 300 800
	// while (ptr->dead)
	/*{
		if philo must eat then
		{
			while philo doesnt have 2 forks (1 left 1 right)
			{
				grab forks (define wich fork must be grabbed)
				if dead
					end_programme();
			}
			eat
			drop forks
			save last meal time
		}
		else if philo must sleep
		{
			sleep
			save sleep time
		}
		else
			think
	}*/
}
