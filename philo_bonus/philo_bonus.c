/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:35:37 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/25 20:26:00 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_table	*table;

	parsing_arg(ac, av);
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	init_table(table, av);
	if (table)
		ft_free(table);
	return (0);
}
