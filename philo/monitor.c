/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:34:55 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/23 15:24:13 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meals(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_lock(&table->counter_lock);
		if ((table->limit_meals != table->philo[i].meals_counter))
		{
			pthread_mutex_unlock(&table->counter_lock);
			return (0);
		}
		pthread_mutex_unlock(&table->counter_lock);
		i++;
	}
	return (1);
}

int	is_dead(t_table *table)
{
	int	i;

	while (1)
	{
		i = 0;
		if (check_meals(table))
			return (1);
		while (i < table->philo_nbr)
		{
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
