/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:56:56 by merlich           #+#    #+#             */
/*   Updated: 2022/04/06 20:59:30 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

# define ERROR_ARGS	"Check your input!\n\
The program takes the following arguments: \n\
1) number_of_philosophers (value > 0)\n\
2) time_to_die (value > 60 ms)\n\
3) time_to_eat (value > 60 ms)\n\
4) time_to_sleep (value > 60 ms)\n\
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

	pthread_mutex_t	*mutex_fork;
	int				*mutex_fork_status;

	pthread_mutex_t	mutex_death;

	int				detached_threads;
	unsigned long	start_time;

}	t_philo;

typedef struct s_thread
{
	pthread_t		thread;
	int				number;
	int				eat_status;
	int				stop_count;
	int				detach_status;

	int				left;
	int				right;
	long long		curr_time;
	long long		last_eat_time;

	t_philo			*data;

}	t_thread;

/* ft_atoi.c */
int				ft_atoi(const char *str);

/* ft_check_input.c */
int				ft_check_input(t_philo data);

/* ft_live.c */
void			*ft_live(void *args);
void			ft_display(t_thread *philos, int flag);

/* threads.c */
t_thread		*ft_create_philos(t_philo *data);
int				ft_detach_philos(t_thread *philos);

/* mutexes.c */
int				ft_create_mutexes(t_philo *data);
int				ft_destroy_mutexes(t_philo *data);

/* time.c */
unsigned long	ft_gettime_ms(t_philo data);
void			ft_msleep(unsigned long us);

#endif
