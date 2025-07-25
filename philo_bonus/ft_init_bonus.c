/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 19:00:47 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/25 15:37:25 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_process(t_table *table)
{
	int	i;
	int	status;

	i = 0;
	while (i < table->philo_nbr)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) == 1)
		{
			i = 0;
			while (i < table->philo_nbr)
				kill(table->pid[i++], SIGKILL);
		}
		i++;
	}
}

void	create_process(t_table *table)
{
	int	i;

	i = 0;
	table->start_time = get_time();
	while (i < table->philo_nbr)
	{
		table->pid[i] = fork();
		if (table->pid[i] == -1)
		{
			ft_print_error("Error: fork failed!\n");
			exit(1);
		}
		if (!table->pid[i])
		{
			table->philo_id = i + 1;
			table->last_meal = table->start_time;
			table->meal_counter = 0;
			philo_routine(table);
		}
		i++;
	}
	wait_process(table);
}

void	init_sem(t_table *table)
{
	sem_unlink("/forks");
	sem_unlink("/print");
	sem_unlink("/meal");
	table->forks = sem_open("/forks", O_CREAT, 0644, table->philo_nbr);
	table->print_lock = sem_open("/print", O_CREAT, 0644, 1);
	table->meal_lock = sem_open("/meal", O_CREAT, 0644, 1);
	if (table->forks == SEM_FAILED || table->print_lock == SEM_FAILED
		|| table->meal_lock == SEM_FAILED)
	{
		ft_print_error("sem_open failed!\n");
		exit(1);
	}
}

void	init_table(t_table	*table, char **av)
{
	table->philo_nbr = ft_atol(av[1]);
	table->time_to_die = ft_atol(av[2]);
	table->time_to_eat = ft_atol(av[3]);
	table->time_to_sleep = ft_atol(av[4]);
	if (av[5])
		table->limit_meals = ft_atol(av[5]);
	else
		table->limit_meals = -1;
	table->pid = malloc(sizeof(int) * table->philo_nbr);
	if (!table->pid)
		exit(1);
	init_sem(table);
	create_process(table);
}
