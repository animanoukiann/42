#ifndef PHILO_H
# define PHILO_H

# define RESET	"\033[0m"
# define GREEN	"\033[32m"      /* Green */
# define RED	"\033[31m"      /* Red */

# include <stdio.h>
# include <limits.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_args
{
    int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	max_eat;
}	t_args;

typedef struct s_const
{
	int	i;
	int	philo_count;
	struct timeval start_time;
}	t_const;

typedef struct s_philo
{
	t_args			info;
	int				philo_count;
	int				id;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_t		philo_thread;
	struct timeval	start_time;
	int				last_time_eaten;//this is time
	pthread_mutex_t	last_time_mutex;
	int				eat_count;//number of times eaten
}	t_philo;

void	parsing(int argc, char **argv);
void	exit_fail(void);
void	exit_success(void);
int		ft_atoi(const char *str);
void	init_mutexes(pthread_mutex_t *forks, t_philo *philo, int philo_count);
void	init_args(pthread_mutex_t *forks, t_philo *philo, t_const consts, char **argv);
void	init_threads(t_philo *philo);
int		get_time(struct timeval given_time);
void	*thread_handler(void *arg);


#endif