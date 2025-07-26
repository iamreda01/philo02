/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:38:28 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/26 15:46:31 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

// libs;
# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_table
{
	int		philo_nbr;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	limit_meals;
	long	start_time;
	long	last_meal;
	int		philo_id;
	int		meal_counter;
	pid_t	*pid;
	sem_t	*forks;
	sem_t	*print_lock;
	sem_t	*meal_lock;
}			t_table;

// parsing;
int			is_nbr(char *str);
void		is_arg_nbr(int ac, char **av);
void		parsing_arg(int ac, char **av);
long		ft_atol(char *str);
void		ft_putstr_fd(char *str, int fd);
void		ft_print_error(char *str);

// helper_func;
long		get_time(void);
void		ft_usleep(long sleep_time);
void		ft_locked_print(t_table *table, char *msg);
void		ft_free(t_table *table);

// init_func;
void		init_table(t_table *table, char **av);
void		init_sem(t_table *table);

// process_management
void		create_process(t_table *table);
void		wait_process(t_table *table);
void		philo_routine(t_table *table);

#endif