/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-kass <rel-kass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:38:20 by rel-kass          #+#    #+#             */
/*   Updated: 2025/07/26 15:42:11 by rel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// libs;
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mutex;
typedef struct s_table	t_table;

typedef struct s_philo
{
	int					id;
	long				last_meal;
	long				meals_counter;
	t_mutex				*right_fork;
	t_mutex				*left_fork;
	pthread_t			tid;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	int					philo_nbr;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				limit_meals;
	long				start_time;
	t_mutex				*forks;
	t_mutex				print_lock;
	t_mutex				meal_lock;
	t_mutex				counter_lock;
	t_philo				*philo;
}						t_table;

// parsing;
int						is_nbr(char *str);
int						is_arg_nbr(int ac, char **av);
int						parsing_arg(int ac, char **av);
long					ft_atol(char *str);
void					ft_putstr_fd(char *str, int fd);
void					ft_print_error(char *str);

// init_func;
int						init_table(t_table *table, char **av);
int						init_forks(t_table *table);
int						init_mutex(t_table *table);
int						init_philo(t_table *table);

// helper_func;
void					ft_locked_print(t_philo *philo, char *msg);
long					get_time(void);
void					ft_usleep(long sleep_time);
void					ft_free(t_table *table);
void					ft_free(t_table *table);
void					ft_mutex_destroy(t_table *table);

// thread_management;
int						create_philo(t_table *table);
void					*philo_routine(void *arg);
void					ft_take_forks(t_philo *philo);
void					ft_eat(t_philo *philo);

// monitor;
int						is_dead(t_table *table);
int						check_meals(t_table *table);

#endif