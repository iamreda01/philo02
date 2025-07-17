/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 21:59:28 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/17 19:22:22 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	
	philo = (t_philo *)arg;
	if (!(philo->id % 2))
		ft_usleep(100);
	while (1)
	{
		pthread_mutex_lock(&philo->table->meal_lock);
		if (philo->meals_counter == philo->table->limit_meals)
			return (pthread_mutex_unlock(&philo->table->meal_lock), NULL);
		pthread_mutex_unlock(&philo->table->meal_lock);
		//-----------------------------------------------------------------------//
		pthread_mutex_lock(philo->left_fork);
		ft_locked_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->right_fork);
		ft_locked_print(philo, "has taken a fork");
		//-----------------------------------------------------------------------//
		pthread_mutex_lock(&philo->table->meal_lock);
		pthread_mutex_lock(&philo->table->counter_lock);
		philo->last_meal = get_time();
		philo->meals_counter += 1;
		printf("philo %d kla ---------> %ld\n", philo->id, philo->meals_counter);
		pthread_mutex_unlock(&philo->table->meal_lock);
		pthread_mutex_unlock(&philo->table->counter_lock);
		ft_locked_print(philo, "is eating");
		ft_usleep(philo->table->time_to_eat);
		//-----------------------------------------------------------------------//
		
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);

		ft_locked_print(philo, "is sleeping");
		ft_usleep(philo->table->time_to_sleep);

		ft_locked_print(philo, "is thinking");
	}
}

int		create_philo(t_table *table)
{
	int		i;
	pthread_t	tid[table->philo_nbr];

	i = 0;
	while (i < table->philo_nbr)
	{
		
		if (pthread_create(&tid[i], NULL, philo_routine, &table->philo[i]))
		{
			printf("Error: Failed to create philosopher thread (id: %d)\n",
				table->philo[i].id);
			return (0);
		}
		pthread_detach(tid[i]);
		i++;
	}
	if (is_dead(table))
		return (0);
	return (1);
}