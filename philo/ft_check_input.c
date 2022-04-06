/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:49:17 by merlich           #+#    #+#             */
/*   Updated: 2022/04/06 23:47:15 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_input(t_philo data)
{
	if (data.num_of_philos < 1 || data.time_to_die < 60 || \
		data.time_to_eat < 60 || data.time_to_sleep < 60 || \
		(data.is_limited == 1 && data.num_must_eat < 0))
	{
		printf(ERROR_ARGS);
		return (1);
	}
	return (0);
}
