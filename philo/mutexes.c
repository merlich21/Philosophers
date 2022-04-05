/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:56:09 by merlich           #+#    #+#             */
/*   Updated: 2022/04/02 21:24:01 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_create_mutexes(t_philo *data)
{
	int	i;

	data->mutex_fork = malloc(sizeof(pthread_mutex_t) * data->num_of_forks);
	i = 0;
	while (i < data->num_of_forks)
	{
		if (pthread_mutex_init(&data->mutex_fork[i], NULL))
		{
			printf("Failed to initialize mutex");
			free(data->mutex_fork);
			return (-1);
		}
		i++;
	}
	if (pthread_mutex_init(&data->mutex_death, NULL))
	{
		printf("Failed to initialize mutex");
		return (-1);
	}
	return (0);
}

int	ft_destroy_mutexes(t_philo *data)
{
	int	i;

	i = 0;
	while (i < data->num_of_forks)
	{
		if (pthread_mutex_destroy(&data->mutex_fork[i]))
		{
			printf("Failed to destroy mutex\n");
			free(data->mutex_fork);
			return (-1);
		}
		i++;
	}
	if (pthread_mutex_destroy(&data->mutex_death))
	{
		printf("Failed to destroy mutex\n");
		return (-1);
	}
	free(data->mutex_fork);
	return (0);
}
