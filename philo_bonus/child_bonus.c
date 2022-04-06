/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:36:25 by merlich           #+#    #+#             */
/*   Updated: 2022/04/06 22:50:01 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_create_philos(t_philo *data)
{
	int		i;
	pid_t	child;

	i = -1;
	while (++i < data->num_of_philos)
	{
		child = fork();
		if (child < 0)
		{
			sem_close(data->sem_fork);
			sem_unlink("forks");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			data->number = i + 1;
			ft_create_detector(data);
			ft_detach_detector(data);
			ft_live(data);
		}
	}
}
