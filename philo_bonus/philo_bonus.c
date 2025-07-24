/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 19:58:17 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/23 21:32:44 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int main(int ac, char **av)
{
	t_table *table;

	parsing_arg(ac, av);
	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	if (!init_table(table, av))
		return (1);
	return (0);
}