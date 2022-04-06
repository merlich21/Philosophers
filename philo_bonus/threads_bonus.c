/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 22:55:30 by merlich           #+#    #+#             */
/*   Updated: 2022/04/06 21:50:38 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_create_detector(t_philo *data)
{
	if (pthread_create(&data->die_detector, NULL, ft_monitoring, (void *) data))
	{
		printf("Failed to create thread\n");
		exit(1);
	}
}

void	ft_detach_detector(t_philo *data)
{
	if (pthread_detach(data->die_detector))
	{
		printf("Failed to detach thread\n");
		exit(1);
	}
}
