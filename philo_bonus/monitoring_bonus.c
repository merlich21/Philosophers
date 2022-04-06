/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:49:37 by merlich           #+#    #+#             */
/*   Updated: 2022/04/06 23:34:33 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_monitoring(void *args)
{
	long long		dt;
	t_philo			*data;

	dt = 0;
	data = (t_philo *) args;
	while (1)
	{
		dt = ft_gettime_ms(*data) - data->last_eat_time;
		if (data->eat_status == 0 && dt >= data->time_to_die && \
			(data->stop_count != data->num_must_eat))
		{
			sem_wait(data->sem_death);
			printf("%ld %d %s\n", ft_gettime_ms(*data), data->number, "died");
			exit(0);
		}
	}
}
