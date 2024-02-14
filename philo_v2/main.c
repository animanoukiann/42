#include "philo.h"

int	go_to_eat(t_philo *philo)
{
	int	start_eat_time;
	int	cur_time;

	start_eat_time = get_time(philo->start_time);
	printf("%d %d is eating\n", start_eat_time, philo->id);
	cur_time = get_time(philo->start_time);
	while (cur_time - start_eat_time < philo->time_to_eat)
		cur_time = get_time(philo->start_time);
	return (cur_time);
}

int	go_to_sleep(t_philo *philo)
{
	int	start_sleep_time;
	int	cur_time;

	start_sleep_time = get_time(philo->start_time);
	printf("%d %d is sleeping\n", start_sleep_time, philo->id);
	cur_time = get_time(philo->start_time);
	while (cur_time - start_sleep_time < philo->time_to_sleep)
		cur_time = get_time(philo->start_time);
	printf("%d %d is thinking\n", cur_time, philo->id);
	return (cur_time);
}

void	*thread_hendler(void *arg)
{
	t_philo	*philo;
	int		time_in_ms;

	philo = (t_philo *)arg;
	printf("Heylo id %d\n",philo->id);
	time_in_ms = get_time(philo->start_time);
	if (philo->id % 2)
		usleep(1500);
	while (1)
	{
		pthread_mutex_lock(&(philo->left_fork));
		pthread_mutex_lock(&(philo->right_fork));
		printf("%d %d has taken forks\n", time_in_ms, philo->id);
		time_in_ms = go_to_eat(philo);
		pthread_mutex_unlock(&(philo->left_fork));
		pthread_mutex_unlock(&(philo->right_fork));
		time_in_ms = go_to_sleep(philo);
	}
	return (NULL);
}

int main(int argc, char **argv)
{
	int				i;
	pthread_mutex_t	*forks;
	pthread_mutex_t	last_eat;
	t_philo			*philo;
	int				philo_count;
	pthread_t		*philo_thread;
	struct			timeval	start_val;

	i = 0;
	parsing(argc, argv);
	gettimeofday(&start_val, NULL);
	philo_count = ft_atoi(argv[1]);
	pthread_mutex_init(&last_eat, NULL);
	philo = (t_philo *)malloc(sizeof(t_philo) * philo_count);
	forks = (pthread_mutex_t *)malloc(sizeof(pthread_t) * philo_count);
	philo_thread = (pthread_t *)malloc((sizeof(pthread_t) * philo_count));
	while (i < philo_count)
		pthread_mutex_init(&forks[i++], NULL);
	pthread_mutex_init(&last_eat, NULL);
	i = 0;
	while (i < philo_count)
	{
		philo[i].id = i;
		philo[i].start_time = start_val;
		philo[i].time_to_die = ft_atoi(argv[2]);
		philo[i].time_to_eat = ft_atoi(argv[3]);
		philo[i].time_to_sleep = ft_atoi(argv[4]);
		if (argv[5])
			philo[i].max_eat = ft_atoi(argv[5]);
		else
			philo[i].max_eat = -1;
		philo[i].last_eat_count = 0;
		philo[i].right_fork = forks[i];
		philo[i].left_fork = forks[i + 1 % philo_count];
		philo[i].last_eat_mutex = &last_eat;
		pthread_create(&philo_thread[i], NULL, &thread_hendler, &philo[i]);
		i++;
	}
	i = 0;
	while (i < philo_count)
	{
		pthread_join(philo_thread[i], NULL);
		i++;
	}
}
