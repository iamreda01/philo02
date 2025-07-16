/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 22:36:17 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/16 17:29:37 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time()
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_locked_print(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->table->print_lock);
	printf("%ld %d %s\n", (get_time() - philo->table->start_time), philo->id, msg);
	pthread_mutex_unlock(&philo->table->print_lock);	
}

void	ft_usleep(long sleep_time)
{
	long	start;

	start = get_time();
	while ((get_time() - start) < sleep_time)
		usleep(50);
}
