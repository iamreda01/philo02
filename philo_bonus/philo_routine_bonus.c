/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:31:29 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/24 18:02:35 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_routine(t_table *table)
{
	while (1)
	{
		sem_wait(table->forks);
		
		sem_wait(table->print_lock);
		printf("%ld %d has taken a fork\n", (get_time() - table->start_time), table->philo_id);
		sem_post(table->print_lock);

		//--------------------------------------------------------------------------------------
		sem_wait(table->forks);
		
		sem_wait(table->print_lock);
		printf("%ld %d has taken a fork\n", (get_time() - table->start_time), table->philo_id);
		sem_post(table->print_lock);
		//--------------------------------------------------------------------------------------
		table->last_meal = get_time();
		
		sem_wait(table->print_lock);
		printf("%ld %d is eating\n", (get_time() - table->start_time), table->philo_id);
		sem_post(table->print_lock);
		
		ft_usleep(table->time_to_eat);
		//--------------------------------------------------------------------------------------

		
		sem_post(table->forks);
		sem_post(table->forks);
		//--------------------------------------------------------------------------------------
		
		
		sem_wait(table->print_lock);
		printf("%ld %d is sleeping\n", (get_time() - table->start_time), table->philo_id);
		sem_post(table->print_lock);
		
		ft_usleep(table->time_to_sleep);
		//--------------------------------------------------------------------------------------

		sem_wait(table->print_lock);
		printf("%ld %d is thinking\n", (get_time() - table->start_time), table->philo_id);
		sem_post(table->print_lock);
	}
}
