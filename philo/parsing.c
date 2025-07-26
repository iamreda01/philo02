/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:01:12 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/26 15:44:21 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_nbr(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	is_arg_nbr(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_nbr(av[i]))
			return (ft_print_error("Error: Invalid argument type!\n"), 0);
		i++;
	}
	return (1);
}

int	parsing_arg(int ac, char **av)
{
	int	i;

	if (!(ac == 5 || ac == 6))
		ft_print_error("Error: Invalid number of arguments!\n");
	if (!is_arg_nbr(ac, av))
		return (0);
	i = 1;
	while (i < ac)
	{
		if (ft_atol(av[i]) == 0)
			return (ft_print_error("Error: Error: wrong argument!\n"), 0);
		if (ft_atol(av[i]) > INT_MAX)
			return (ft_print_error("Error: argument exceeds maximum int!\n"),
				0);
		i++;
	}
	return (1);
}
