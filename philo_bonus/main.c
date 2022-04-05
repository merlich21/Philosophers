/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:24:55 by merlich           #+#    #+#             */
/*   Updated: 2022/04/05 23:53:29 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_error(t_philo *data, int exit_code)
{
	free(data->all_pids);
	sem_close(data.sem_fork);
	sem_unlink("forks");
	exit(exit_code);
}

static void	ft_create_philos(t_philo *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		data->all_pids[i] = fork();
		if (data->all_pids[i] < 0)
		{
			free(data->all_pids);
			sem_close(data.sem_fork);
			sem_unlink("forks");
			exit(EXIT_FAILURE);
		}
		else if (data->all_pids[i] == 0)
		{
			data[i].number = i + 1;
			ft_live(data);
			
		}
	}
}

int	main(int argc, char **argv)
{
	int			j;
	t_philo		data;

	j = -1;
	if (argc < 5 || argc > 6)
		printf(ERROR_ARGS);
	else
	{
		sem_unlink("forks");
		ft_init(&data, argc, argv);
		data.start_time = ft_gettime_ms(data);
		data.all_pids = malloc(sizeof(pid_t) * data.num_of_philos);
		data.sem_fork = sem_open("forks", O_CREAT, 777, data.num_of_forks);

		ft_create_philos(&data);
		while (++j < data.num_of_philos)
			waitpid(data.all_pids[j], NULL, WUNTRACED);
		free(data.all_pids);
		sem_close(data.sem_fork);
		sem_unlink("forks");
	}
	return (0);
}
