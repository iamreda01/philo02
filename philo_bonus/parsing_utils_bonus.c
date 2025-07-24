/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:04:25 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/24 16:37:46 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	ft_atol(char *str)
{
	int		sign;
	long	res;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (res > res * 10 + (*str - '0'))
			return (2147483649);
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * sign);
}

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (fd < 0)
		return ;
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_print_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
