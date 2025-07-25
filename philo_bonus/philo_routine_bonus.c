/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:31:29 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/25 15:10:10 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*is_dead(void *arg)
{
	t_table *table;

	table = (t_table *)arg;
	while (1)
	{
		sem_wait(table->meal_lock);
		if ((get_time() - table->last_meal) > table->time_to_die)
		{
			sem_wait(table->print_lock);
			printf("%ld %d died\n", (get_time() - table->start_time), table->philo_id);
			exit (1);
		}
		sem_post(table->meal_lock);
	}	
}

void	philo_routine(t_table *table)
{
	pthread_t	tid;

	if (pthread_create(&tid, NULL, is_dead, table))
		ft_print_error("Error: Failed to create philosopher thread\n");
	pthread_detach(tid);
	while (1)
	{
		if (table->meal_counter == table->limit_meals)
			exit(1);
		
		sem_wait(table->forks);
		
		ft_locked_print(table, "has taken a fork");
		//--------------------------------------------------------------------------------------
		sem_wait(table->forks);
		
		ft_locked_print(table, "has taken a fork");
		//--------------------------------------------------------------------------------------
		sem_wait(table->meal_lock);
		table->last_meal = get_time();
		table->meal_counter++;
		sem_post(table->meal_lock);
		
		ft_locked_print(table, "is eating");
		ft_usleep(table->time_to_eat);
		//--------------------------------------------------------------------------------------

		
		sem_post(table->forks);
		sem_post(table->forks);
		//--------------------------------------------------------------------------------------
		
		ft_locked_print(table, "is sleeping");
		ft_usleep(table->time_to_sleep);
		//--------------------------------------------------------------------------------------

		ft_locked_print(table, "is thinking");
	}
}
