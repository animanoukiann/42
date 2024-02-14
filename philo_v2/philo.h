#ifndef PHILO_H
# define PHILO_H

# define RESET	"\033[0m"
# define GREEN	"\033[32m"      /* Green */
# define RED	"\033[31m"      /* Red */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_eat;
	int				last_eat_count;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*last_eat_mutex;
	struct			timeval start_time;
}	t_philo;

void	parsing(int argc, char **argv);
int		ft_atoi(const char *str);
int		get_time(struct timeval given_time);

#endif