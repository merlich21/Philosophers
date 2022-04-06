/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:24:55 by merlich           #+#    #+#             */
/*   Updated: 2022/04/06 23:40:58 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	int			i;
	t_philo		data;

	i = -1;
	if (argc < 5 || argc > 6)
		printf(ERROR_ARGS);
	else
	{
		sem_unlink("forks");
		sem_unlink("death");
		ft_init(&data, argc, argv);
		ft_check_input(data);
		data.start_time = ft_gettime_ms(data);
		data.sem_fork = sem_open("forks", O_CREAT, 777, data.num_of_forks);
		data.sem_death = sem_open("death", O_CREAT, 777, 1);
		ft_create_philos(&data);
		waitpid(-1, NULL, WUNTRACED);
		kill(0, SIGINT);
		sem_close(data.sem_fork);
		sem_close(data.sem_death);
		sem_unlink("forks");
		sem_unlink("death");
	}
	return (0);
}
