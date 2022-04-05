/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:34:31 by merlich           #+#    #+#             */
/*   Updated: 2021/10/20 17:49:41 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_isspace(const char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\f' || str[*i] == '\n' || \
			str[*i] == '\r' || str[*i] == '\t' || str[*i] == '\v')
	{
		*i = *i + 1;
	}
	return ;
}

static void	ft_issign(const char *str, int *i, int *flag_sign)
{
	if (str[*i] == '-')
	{
		*flag_sign = -1;
		*i = *i + 1;
	}
	else if (str[*i] == '+')
	{
		*flag_sign = 1;
		*i = *i + 1;
	}
	return ;
}

static void	ft_iszero(const char *str, int *i)
{
	while (str[*i] == '0')
	{
		*i = *i + 1;
	}
	return ;
}

int	ft_atoi(const char *str)
{
	int			i;
	int			j;
	int			flag_sign;
	long long	res;

	i = 0;
	j = 0;
	flag_sign = 1;
	res = 0;
	ft_isspace(str, &i);
	ft_issign(str, &i, &flag_sign);
	ft_iszero(str, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		j++;
		if ((j >= 19) && (flag_sign == 1))
			return (-1);
		if ((j >= 19) && (flag_sign == -1))
			return (0);
		res = res * 10 + (str[i] - '0');
		i = i + 1;
	}
	return ((int)(res * flag_sign));
}
