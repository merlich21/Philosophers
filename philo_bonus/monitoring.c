/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:49:37 by merlich           #+#    #+#             */
/*   Updated: 2022/04/05 23:50:36 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_catch_death(t_thread *philos, t_philo *data)
{
	int				i;
	long long		dt;

	i = -1;
	dt = 0;
	data->detached_threads = 0;
	while (++i < data->num_of_philos)
	{
		if (philos[i].detach_status != 1)
		{
			dt = ft_gettime_ms(*data) - philos[i].last_eat_time;
			if (philos[i].eat_status == 0 && dt >= data->time_to_die)
			{
				pthread_mutex_lock(&data->mutex_death);
				printf("%ld %d %s\n", ft_gettime_ms(*data), \
										philos[i].number, "died");
				if (ft_cleanup(philos, data))
					return (-1);
				return (0);
			}
		}
		else
			data->detached_threads++;
	}
	return (1);
}

int	ft_monitoring(t_thread *philos, t_philo *data)
{
	int	res;

	res = 0;
	while (1)
	{
		res = ft_catch_death(philos, data);
		if (res != 1)
			break ;
		if (data->detached_threads == data->num_of_philos)
		{
			free(data->mutex_fork);
			free(philos);
			res = 0;
			break ;
		}
	}
	return (res);
}
