#ifndef PHILO_H
# define PHILO_H


// libs;
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <limits.h>
# include <sys/time.h>


typedef pthread_mutex_t	mutex_t;
typedef struct	s_table t_table;


typedef struct	s_philo
{
	int		id;
	long	last_meal;
	long	meals_counter;
	long	start_time;
	mutex_t	*right_fork;
	mutex_t	*left_fork;
	t_table	*table;
}	t_philo;

typedef struct	s_table
{
	int			philo_nbr; // [1];
	long    	time_to_die; // [2];
	long    	time_to_eat; // [3];
	long    	time_to_sleep; // [4];
	long    	limit_meals; // [5] optional arg
	mutex_t		*forks;
	t_philo		*philo;
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
int		init_mutex(t_table *table);

# endif