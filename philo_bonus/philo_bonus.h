#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H


// libs;
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/wait.h> 
# include <signal.h>

typedef struct	s_table
{
	int			philo_nbr; // [1];
	long    	time_to_die; // [2];
	long    	time_to_eat; // [3];
	long    	time_to_sleep; // [4];
	long    	limit_meals; // [5] optional arg
	long		start_time;
	sem_t		*forks;
	sem_t		*print_lock;
	pid_t		*pid;
}	t_table;


// parsing;
int		is_nbr(char *str);
void	is_arg_nbr(int ac, char **av);
void	parsing_arg(int ac, char **av);
long	ft_atol(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_print_error(char *str);

// init_func;
int		init_table(t_table	*table, char **av);
void	init_semaphores(t_table *table);

// helper_func;
void	ft_locked_print(t_table *table, int pid, long last_meal, char *msg);
long	get_time();
void	ft_usleep(long sleep_time);
void	ft_free(t_table *table);

// monitor;
int		is_dead(t_table *table);
int		check_meals(t_table *table);

//process_manaegment
void	philo_routine(t_table *table, int i);
void	check_death(t_table *table, long last_meal, int philo_id);


# endif