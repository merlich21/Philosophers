/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:24:55 by merlich           #+#    #+#             */
/*   Updated: 2022/03/31 22:06:33 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_init(t_philo *data, int argc, char **argv)
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
	data->mutex_fork = NULL;
	data->start_time = 0;
	data->detached_threads = 0;
}

static int	ft_cleanup(t_thread *philos, t_philo *data)
{
	if (ft_detach_philos(philos))
		return (3);
	free(data->mutex_fork);
	return (0);
}

static int	ft_catch_death(t_thread *philos, t_philo *data)
{
	int				i;
	long long		dt;

	i = 0;
	dt = 0;
	data->detached_threads = 0;
	while (i < data->num_of_philos)
	{
		if (philos[i].detach_status != 1)
		{
			dt = ft_gettime_ms(*data) - philos[i].last_eat_time;
			if (philos[i].eat_status == 0 && dt >= data->time_to_die)
			{
				pthread_mutex_lock(&data->mutex_death);
				ft_display(&philos[i], 4);
				if (ft_cleanup(philos, data))
					return (-1);
				return (0);
			}
		}
		else
			data->detached_threads++;
		i++;
	}
	return (1);
}

static int	ft_monitoring(t_thread *philos, t_philo *data)
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

int	main(int argc, char **argv)
{
	t_thread		*philos;
	t_philo			data;

	philos = NULL;
	if (argc < 5 || argc > 6)
		printf(ERROR_ARGS);
	else
	{
		ft_init(&data, argc, argv);
		if (ft_create_mutexes(&data))
			return (1);
		data.start_time = ft_gettime_ms(data);
		philos = ft_create_philos(&data);
		if (!philos)
			return (2);
		if (ft_monitoring(philos, &data))
			return (-1);
	}
	return (0);
}
