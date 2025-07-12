/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:00:47 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/12 19:11:22 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int		init_mutex(t_table *table)
{
	int		i;

	i = 0;
	table->forks = malloc(sizeof(table->forks) * table->philo_nbr);
	if (!table->forks)
		return (0);
	while (i < table->philo_nbr)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
			return (0);
		i++;
	}
	return (1);
}


int		init_table(t_table	*table, char **av)
{
	table = malloc(sizeof(t_table));
	if (!table)
		return (0);
	table->philo_nbr = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		table->limit_meals = ft_atol(av[5]);
	if (!init_mutex(table))
		return (0);
	return (1);	
}
