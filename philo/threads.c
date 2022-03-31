/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:55:30 by merlich           #+#    #+#             */
/*   Updated: 2022/03/31 22:06:07 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init_vals(t_thread *philo)
{
	philo->left = 0;
	philo->right = 0;
	philo->curr_time = 0;
	philo->last_eat_time = 0;
	philo->eat_status = 0;
	philo->stop_count = 0;
	philo->detach_status = 0;
}

t_thread	*ft_create_philos(t_philo *data)
{
	t_thread	*philos;
	int			i;

	philos = malloc(sizeof(t_thread) * data->num_of_philos);
	i = 0;
	while (i < data->num_of_philos)
	{
		ft_init_vals(&philos[i]);
		philos[i].number = i + 1;
		philos[i].data = data;
		if (pthread_create(&philos[i].thread, NULL, \
							ft_live, (void *) &philos[i]))
		{
			printf("Failed to create thread\n");
			free(data->mutex_fork);
			free(philos);
			return (NULL);
		}
		i++;
	}
	return (philos);
}

int	ft_detach_philos(t_thread *philos)
{
	int	j;

	j = 0;
	while (j < philos->data->num_of_philos)
	{
		if (philos[j].detach_status != 1)
		{
			philos[j].detach_status = 1;
			if (pthread_detach(philos[j].thread))
			{
				printf("Failed to detach thread\n");
				free(philos->data->mutex_fork);
				free(philos);
				return (-1);
			}
		}
		j++;
	}
	free(philos);
	return (0);
}
