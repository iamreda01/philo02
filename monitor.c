/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 01:34:55 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/15 02:37:25 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		is_dead(t_table *table)
{
	int		i;

	while (1)
	{
		i = 0;
		while (i < table->philo_nbr)
		{
			pthread_mutex_lock(&table->meal_lock);
			if ((get_time() - table->philo[i].last_meal) > table->time_to_die)
			{
				pthread_mutex_unlock(&table->meal_lock);
				ft_locked_print(&table->philo[i], " died");
				return (1);
			}
			pthread_mutex_unlock(&table->meal_lock);
			i++;
		}
	}
	return (0);
}