/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 15:02:39 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/26 15:37:36 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_table	*table;

	if (!parsing_arg(ac, av))
		return (1);
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	if (!init_table(table, av))
		return (ft_free(table), 1);
	ft_mutex_destroy(table);
	ft_free(table);
	return (0);
}
