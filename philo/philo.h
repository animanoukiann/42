#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

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
	pthread_mutex_t	*forks;
	pthread_t		philo_thread;
	struct timeval	start_time;
	int				last_time_eaten;//this is time
	pthread_mutex_t	last_time_mutex;
	int				eat_count;//number of times eaten
}	t_philo;

void	exit_fail(void);
int		get_time(struct timeval given_time);
int		ft_atoi(const char *str);
void    parsing(int argc, char **argv);
void    init_args(t_args *obj, char **argv);
void	init_philo(t_philo *obj, char **argv, t_args a, int i);
void	init_mutexes(pthread_mutex_t *fork, t_philo *obj, int philo_count);
void	init_threads(t_philo *obj);
void    *thread_hendler(void *arg);

#endif