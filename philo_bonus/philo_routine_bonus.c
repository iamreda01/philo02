/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 20:50:40 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/24 15:29:05 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_death(t_table *table, long last_meal, int philo_id)
{
	if ((get_time() - last_meal) > table->time_to_die)
	{
		sem_wait(table->print_lock);
		printf("%ld %d died\n", (get_time() - table->start_time), philo_id);
		exit (1);
	}
}

void	philo_routine(t_table *table, int i)
{
	int		meal_counter;
	long	last_meal;

	(1) && (meal_counter = 0, last_meal = 0);
	while (1)
	{
		sem_wait(table->forks);
		ft_locked_print(table, i, last_meal, "has taken a fork");
		sem_wait(table->forks);
		printf("m here\n");
		ft_locked_print(table, i, last_meal, "has taken a fork");

		meal_counter++;
		last_meal = get_time();
		ft_locked_print(table, i, last_meal, "is eating");
		ft_usleep(table->time_to_eat);
		
		sem_post(table->forks);
		sem_post(table->forks);

		ft_locked_print(table, i, last_meal, "is sleeping");
		ft_usleep(table->time_to_sleep);

		ft_locked_print(table, i, last_meal, "is sleeping");
		ft_usleep(table->time_to_sleep);

		ft_locked_print(table, i, last_meal, "is thinking");
	}
}
