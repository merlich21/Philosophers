/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:56:56 by merlich           #+#    #+#             */
/*   Updated: 2022/04/06 22:59:55 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <pthread.h>
# include <signal.h>
# include <semaphore.h>

# define ERROR_ARGS	"Check your input!\n\
The program takes the following arguments: \n\
1) number_of_philosophers \n\
2) time_to_die\n\
3) time_to_eat\n\
4) time_to_sleep\n\
5) [number_of_times_each_philosopher_must_eat] (optional argument)\n"

typedef struct s_philo
{
	int				num_of_philos;
	int				num_of_forks;
	long long		time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	long long		num_must_eat;
	int				is_limited;

	sem_t			*sem_fork;
	sem_t			*sem_death;

	unsigned long	start_time;

	pid_t			process;
	int				number;
	int				eat_status;
	int				stop_count;

	long long		curr_time;
	long long		last_eat_time;

	pthread_t		die_detector;

}	t_philo;

/* child.c */
void			ft_create_philos(t_philo *data);

/* ft_atoi.c */
int				ft_atoi(const char *str);

/* init.c */
void			ft_init(t_philo *data, int argc, char **argv);

/* ft_check_input.c */
void			ft_check_input(t_philo data);

/* threads.c */
void			ft_create_detector(t_philo *data);
void			ft_detach_detector(t_philo *data);

/* monitoring.c */
void			*ft_monitoring(void *args);

/* ft_live.c */
void			ft_live(t_philo *data);
void			ft_display(t_philo data, int flag);

/* time.c */
unsigned long	ft_gettime_ms(t_philo data);
void			ft_msleep(unsigned long us);

#endif
