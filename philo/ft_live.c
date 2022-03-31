/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:02:47 by merlich           #+#    #+#             */
/*   Updated: 2022/03/31 22:27:39 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_set_vals(t_thread *philo)
{
	if (philo->number == 1)
	{
		philo->left = 0;
		philo->right = philo->data->num_of_forks - 1;
	}
	else
	{
		philo->left = philo->number - 1;
		philo->right = philo->number - 2;
	}
}

static void	ft_delay(t_thread *philo)
{
	if (philo->number % 2 == 0)
	{
		ft_display(philo, 3);
		ft_msleep(philo->data->time_to_eat);
	}
}

void	*ft_live(void *args)
{
	t_thread	*philo;

	philo = (t_thread *) args;
	ft_delay(philo);
	ft_set_vals(philo);
	while (philo->stop_count != philo->data->num_must_eat)
	{
		pthread_mutex_lock(&philo->data->mutex_fork[philo->left]);
		ft_display(philo, 0);
		pthread_mutex_lock(&philo->data->mutex_fork[philo->right]);
		ft_display(philo, 0);
		philo->last_eat_time = ft_gettime_ms(*philo->data);
		philo->eat_status = 1;
		ft_display(philo, 1);
		if (philo->data->is_limited)
			philo->stop_count++;
		pthread_mutex_unlock(&philo->data->mutex_fork[philo->left]);
		pthread_mutex_unlock(&philo->data->mutex_fork[philo->right]);
		philo->last_eat_time = ft_gettime_ms(*philo->data);
		philo->eat_status = 0;
		ft_display(philo, 2);
		ft_display(philo, 3);
	}
	philo->detach_status = 1;
	return (NULL);
}

static void	ft_print_msg(char *msg, t_thread philo)
{
	printf("%ld %d %s\n", ft_gettime_ms(*philo.data), philo.number, msg);
}

void	ft_display(t_thread *philo, int flag)
{
	if (flag == 0)
		ft_print_msg("has taken a fork", *philo);
	else if (flag == 1)
	{
		ft_print_msg("is eating", *philo);
		ft_msleep(philo->data->time_to_eat);
	}
	else if (flag == 2)
	{
		ft_print_msg("is sleeping", *philo);
		ft_msleep(philo->data->time_to_sleep);
	}
	else if (flag == 3)
		ft_print_msg("is thinking", *philo);
	else if (flag == 4)
		ft_print_msg("died", *philo);
}
