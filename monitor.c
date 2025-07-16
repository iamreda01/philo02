/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:34:55 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/16 17:49:16 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		is_meal_limit_reached(t_table *table, int philo_index)
{
	pthread_mutex_lock(&table->counter_lock);
	if (table->limit_meals <= table->philo[philo_index].meals_counter)
		return (1);
	pthread_mutex_unlock(&table->counter_lock);
	return (0);
}

int		is_dead(t_table *table)
{
	int		i;

	ft_usleep(800);
	while (1)
	{
		i = 0;
		while (i < table->philo_nbr)
		{
			if (table->limit_meals)
			{
				if (is_meal_limit_reached(table, i))
				{
					pthread_mutex_lock(&table->print_lock);
					printf("%ld %d is dead\n", (get_time() - table->start_time),
							table->philo[i].id);
					return (1);
				}
			}
			pthread_mutex_lock(&table->meal_lock);
			if ((get_time() - table->philo[i].last_meal) > table->time_to_die)
			{
				pthread_mutex_lock(&table->print_lock);
				printf("%ld %d is dead\n", (get_time() - table->start_time),
						table->philo[i].id);
				return (1);
			}
			pthread_mutex_unlock(&table->meal_lock);
			i++;
		}
	}
	return (0);
}
