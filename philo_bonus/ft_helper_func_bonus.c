/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_func_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:36:17 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/24 15:26:53 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(long sleep_time)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(50);
}

void	ft_locked_print(t_table *table, int philo_id, long last_meal, char *msg)
{
	// check_death(table, philo_id, last_meal);
	sem_wait(table->print_lock);
	printf("%ld %d %s\n", (get_time() - table->start_time), philo_id, msg);
	sem_post(table->print_lock);	
}
