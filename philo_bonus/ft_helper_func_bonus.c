/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_func_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:36:17 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/25 15:42:24 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_locked_print(t_table *table, char *msg)
{
	sem_wait(table->print_lock);
	printf("%ld %d %s\n", (get_time() - table->start_time),
		table->philo_id, msg);
	sem_post(table->print_lock);
}

void	ft_usleep(long sleep_time)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(50);
}
