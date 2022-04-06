/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:51:59 by merlich           #+#    #+#             */
/*   Updated: 2022/04/06 22:44:29 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_null_init(t_philo *data)
{
	data->sem_fork = 0;
	data->start_time = 0;
	data->process = 0;
	data->number = 0;
	data->eat_status = 0;
	data->stop_count = 0;
	data->curr_time = 0;
	data->last_eat_time = 0;
	data->die_detector = 0;
}

void	ft_init(t_philo *data, int argc, char **argv)
{
	data->num_of_philos = ft_atoi(argv[1]);
	data->num_of_forks = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		data->num_must_eat = ft_atoi(argv[5]);
		data->is_limited = 1;
	}
	else
	{
		data->num_must_eat = -1;
		data->is_limited = 0;
	}
	ft_null_init(data);
}
