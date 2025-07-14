/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:00:47 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/14 23:50:21 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		init_philo(t_table *table)
{
	int		i;

	i = 0;
	table->philo = malloc(sizeof(t_philo) * table->philo_nbr);
	if (!table->philo)
		return (0);
	while (i < table->philo_nbr)
	{
		table->philo[i].id = i + 1;
		table->philo[i].left_fork = &table->forks[i];
		table->philo[i].right_fork = &table->forks[(i + 1) % table->philo_nbr];
		table->philo[i].table = table;
		i++;
	}
	return (1);
	
}

int		init_mutex(t_table	*table)
{
	if (pthread_mutex_init(&table->print_lock, NULL)
		|| pthread_mutex_init(&table->print_lock, NULL))
	{
			printf("Error: Failed to initialize mutex\n");
			return (0);
	}
	return (1);
}

int		init_forks(t_table *table)
{
	int		i;

	i = 0;
	table->forks = malloc(sizeof(table->forks) * table->philo_nbr);
	if (!table->forks)
		return (0);
	while (i < table->philo_nbr)
	{
		if (pthread_mutex_init(&table->forks[i], NULL))
		{
			printf("Error: Failed to init fork mutex.\n");
			return (0);
		}
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
	if (!init_forks(table))
		return (0);
	if (!init_mutex(table))
		return (0);
	if (!init_philo(table))
		return (0);
	if (!create_philo(table))
		return (0);
	return (1);	
}
