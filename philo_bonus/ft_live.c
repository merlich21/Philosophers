/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:02:47 by merlich           #+#    #+#             */
/*   Updated: 2022/04/05 23:51:12 by merlich          ###   ########.fr       */
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

void	*ft_live(t_philo *data)
{
	ft_delay(*data);
	while (data->stop_count != data->num_must_eat)
	{
		// pthread_mutex_lock(&philo->data->mutex_fork[philo->left]);
		ft_display(*data, 0);
		// pthread_mutex_lock(&philo->data->mutex_fork[philo->right]);
		ft_display(*data, 0);
		data->eat_status = 1;
		ft_display(*data, 1);
		if (data->is_limited)
			data->stop_count++;
		// pthread_mutex_unlock(&philo->data->mutex_fork[philo->left]);
		// pthread_mutex_unlock(&philo->data->mutex_fork[philo->right]);
		data->eat_status = 0;
		data->last_eat_time = ft_gettime_ms(*data);
		ft_display(*data, 2);
		ft_display(*data, 3);
	}
	// philo->detach_status = 1;
	return (NULL);
}

static void	ft_print_msg(char *msg, t_philo data)
{
	printf("%ld %d %s\n", ft_gettime_ms(data), data.number, msg);
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
