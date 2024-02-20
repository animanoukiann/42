#include "philo.h"

void    init_mutexes(pthread_mutex_t *forks, t_philo *philo, int philo_count)
{
    int	i;

	i = 0;
	while (i < philo_count)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			exit_fail();
		if (pthread_mutex_init(&(philo[i].last_time_mutex), NULL) != 0)
			exit_fail();
		i++;
	}
}

void	init_args(pthread_mutex_t *forks, t_philo *philo, t_const consts, char ** argv)
{
	int	i;

	i = 0;
	while (i < consts.philo_count)
	{
		philo[i].philo_count = consts.philo_count;
		philo[i].id = i;
		philo[i].start_time = consts.start_time;
		philo[i].eat_count = 0;
		philo[i].info.time_to_die = ft_atoi(argv[2]);
		philo[i].info.time_to_eat = ft_atoi(argv[3]);
		philo[i].info.time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			philo[i].info.max_eat = ft_atoi(argv[5]);
		else
			philo[i].info.max_eat = -1;
		philo[i].last_time_eaten = 0;
		philo[i].right_fork = &forks[i];
		philo[i].left_fork = &forks[(i + 1) % consts.philo_count];
		i++;
	}
}

void	init_threads(t_philo *philo)
{
	int			i;
	const int	count = philo[0].philo_count;

	i = 0;
	while (i < count)
	{
		if (pthread_create(&(philo[i].philo_thread), NULL, &thread_handler, &philo[i]) != 0)
			exit_fail();
		i++;
	}
	i = 0;
	while (i < count)
	{
		if (pthread_detach(philo[i].philo_thread) != 0)
			exit_fail();
		i++;
	}
}