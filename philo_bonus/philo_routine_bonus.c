/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:31:29 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/24 20:13:00 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*is_dead(void *arg)
{
	t_table *table;

	table = (t_table *)arg;
	while (1)
	{
		if ((get_time() - table->last_meal) > table->time_to_die)
		{
			sem_wait(table->print_lock);
			printf("%ld %d died\n", (get_time() - table->start_time), table->philo_id);
			exit (1);
		}
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
