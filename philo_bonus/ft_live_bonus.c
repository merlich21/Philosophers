/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:02:47 by merlich           #+#    #+#             */
/*   Updated: 2022/04/06 23:38:21 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_delay(t_philo data)
{
	if (data.number % 2 == 0)
	{
		ft_display(data, 3);
		ft_msleep(data.time_to_eat);
	}
}

void	ft_live(t_philo *data)
{
	ft_delay(*data);
	while (data->stop_count != data->num_must_eat)
	{
		sem_wait(data->sem_fork);
		ft_display(*data, 0);
		sem_wait(data->sem_fork);
		ft_display(*data, 0);
		data->eat_status = 1;
		ft_display(*data, 1);
		if (data->is_limited)
			data->stop_count++;
		sem_post(data->sem_fork);
		sem_post(data->sem_fork);
		data->eat_status = 0;
		data->last_eat_time = ft_gettime_ms(*data);
		ft_display(*data, 2);
		ft_display(*data, 3);
	}
	ft_msleep(data->time_to_eat * (data->num_of_philos / 2));
}

static void	ft_print_msg(char *msg, t_philo data)
{
	sem_wait(data.sem_death);
	printf("%ld %d %s\n", ft_gettime_ms(data), data.number, msg);
	sem_post(data.sem_death);
}

void	ft_display(t_philo data, int flag)
{
	if (flag == 0)
		ft_print_msg("has taken a fork", data);
	else if (flag == 1)
	{
		ft_print_msg("is eating", data);
		ft_msleep(data.time_to_eat);
	}
	else if (flag == 2)
	{
		ft_print_msg("is sleeping", data);
		ft_msleep(data.time_to_sleep);
	}
	else if (flag == 3)
		ft_print_msg("is thinking", data);
}
