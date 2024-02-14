/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsarda <jsarda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 10:49:37 by jsarda            #+#    #+#             */
/*   Updated: 2024/02/14 13:07:12 by jsarda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*safe_malloc(size_t bytes)
{
	void	*ret;

	ret = malloc(bytes);
	if (!ret)
		error_exit("Error allocating memory");
	return (ret);
}

/*Threads errors*/
static void	thread_error(int status, t_operation operation)
{
	if (status == 0)
		return ;
	if (EAGAIN == status)
		error_exit("No resources to create another thread");
	else if (EPERM == status)
		error_exit("The caller does not have appropriate permission\n");
	else if (EINVAL == status && CREATE == operation)
		error_exit("The value specified by attr is invalid.");
	else if (EINVAL == status && (JOIN == operation || DETACH == operation))
		error_exit("The value specified by thread is not joinable\n");
	else if (ESRCH == status)
		error_exit("No thread could be found corresponding to that"
					"specified by the given thread ID, thread.");
	else if (EDEADLK == status)
		error_exit("A deadlock was detected or the value of"
					"thread specifies the calling thread.");
}

// safe thread handler
void	safe_thread(pthread_t *thread, void *(*foo)(void *), void *data,
		t_operation operation)
{
	if (CREATE == operation)
		thread_error(pthread_create(thread, NULL, foo, data), operation);
	else if (JOIN == operation)
		thread_error(pthread_join(*thread, NULL), operation);
	else if (DETACH == operation)
		thread_error(pthread_detach(*thread), operation);
	else
		error_exit("You can only use <CREATE> <JOIN> or <DETACH> threads operation !");
}
