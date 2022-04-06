/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:53:44 by merlich           #+#    #+#             */
/*   Updated: 2022/04/05 21:44:25 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

unsigned long	ft_gettime_ms(t_philo data)
{
	struct timeval	t;
	unsigned long	ms;	

	gettimeofday(&t, NULL);
	ms = t.tv_sec * 1000 + t.tv_usec / 1000 - data.start_time;
	return (ms);
}

static unsigned long	ft_get_time(void)
{
	struct timeval	t;
	unsigned long	ms;	

	gettimeofday(&t, NULL);
	ms = t.tv_sec * 1000 + t.tv_usec / 1000;
	return (ms);
}

void	ft_msleep(unsigned long us)
{
	unsigned long	t1;
	unsigned long	t2;
	unsigned long	dt;

	dt = 0;
	t1 = ft_get_time();
	while (dt < us)
	{
		t2 = ft_get_time();
		dt = t2 - t1;
		usleep(500);
	}
}
