#include "philo.h"

void    init_args(t_args *obj, char **argv)
{
    obj->time_to_die = ft_atoi(argv[2]);
    obj->time_to_eat = ft_atoi(argv[3]);
    obj->time_to_sleep = ft_atoi(argv[4]);
    if (argv[5])
        obj->max_eat = ft_atoi(argv[5]);
}

void	init_mutexes(pthread_mutex_t *fork, t_philo *obj, int philo_count)
{
	int	i;

	while (i < philo_count)
	{
		if (pthread_mutex_init(&fork[i], NULL) != 0)
			exit_fail();
		if (pthread_mutex_init(&(obj[i].last_time_mutex), NULL) != 0)
			exit_fail();
		i++;
	}
}

void	init_philo(t_philo *obj, char **argv, t_args a, int i)
{
	obj->philo_count = ft_atoi(argv[1]);
	obj->id = i;
	obj->info = a;
	obj->last_time_eaten = 0;
	obj->eat_count = 0;
}

void	init_threads(t_philo *obj)
{
	if (pthread_create(&(obj->philo_thread), NULL, &thread_hendler, obj) != 0)
		exit_fail();

	if (pthread_join(obj->philo_thread, NULL) != 0)
		exit_fail();
}