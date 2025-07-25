/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:36:17 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/25 16:35:19 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_locked_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->print_lock);
	printf("%ld %d %s\n", (get_time() - philo->table->start_time),
		philo->id, msg);
	pthread_mutex_unlock(&philo->table->print_lock);
}

void	ft_usleep(long sleep_time)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(50);
}

void	ft_free(t_table *table)
{
	if (table->philo)
		free(table->philo);
	if (table->forks)
		free(table->forks);
	if (table)
		free(table);
}

void	ft_mutex_destroy(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
}
