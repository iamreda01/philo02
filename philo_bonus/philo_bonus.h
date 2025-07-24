#ifndef PHILO_H
# define PHILO_H


// libs;
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>



typedef struct	s_table
{
	int			philo_nbr; // [1];
	long    	time_to_die; // [2];
	long    	time_to_eat; // [3];
	long    	time_to_sleep; // [4];
	long    	limit_meals; // [5] optional arg
	long		start_time;
	long		last_meal;
	int			philo_id;
	int			meal_counter;
	pid_t		*pid;
	sem_t		*forks;
	sem_t		*print_lock;
}	t_table;

// parsing;
int		is_nbr(char *str);
void	is_arg_nbr(int ac, char **av);
void	parsing_arg(int ac, char **av);
long	ft_atol(char *str);
void	ft_putstr_fd(char *str, int fd);
void	ft_print_error(char *str);

// helper_func;
long	get_time();
void	ft_usleep(long sleep_time);

// init_func;
void	init_table(t_table	*table, char **av);
void	init_sem(t_table *table);

// process_management
void	create_process(t_table *table);
void	philo_routine(t_table *table);

# endif