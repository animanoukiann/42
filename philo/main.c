#include "philo.h"

int	go_to_eat(t_philo *philo)
{
	int	start_eat_time;
	int	cur_time;

	start_eat_time = get_time(philo->start_time);
	printf("%d {%d} is eating\n", start_eat_time, philo->id);
	cur_time = get_time(philo->start_time);
	while (cur_time - start_eat_time < philo->info.time_to_eat)
		cur_time = get_time(philo->start_time);
	return (cur_time);
}

int	go_to_sleep(t_philo *philo)
{
	int	start_sleep_time;
	int	cur_time;

	start_sleep_time = get_time(philo->start_time);
	printf("%d {%d} is sleeping\n", start_sleep_time, philo->id);
	cur_time = get_time(philo->start_time);
	while (cur_time - start_sleep_time < philo->info.time_to_sleep)
		cur_time = get_time(philo->start_time);
	printf("%d {%d} is thinking\n", cur_time, philo->id);
	return (cur_time);
}

void changes(t_philo *philo, int time)
{
    philo->last_time_eaten = time;
    philo->eat_count++;
}

void	*thread_handler(void *arg)
{
	t_philo	*philo;
	int		time_in_ms;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		usleep(1500);
	}
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
	    time_in_ms = get_time(philo->start_time);
		printf("%d {%d} has taken a left fork\n", time_in_ms, philo->id);
		pthread_mutex_lock(philo->right_fork);
		time_in_ms = get_time(philo->start_time);
		printf("%d {%d} has taken a right fork\n", time_in_ms, philo->id);
		time_in_ms = go_to_eat(philo);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_lock(&(philo->last_time_mutex));
        changes(philo, time_in_ms);
        pthread_mutex_unlock(&(philo->last_time_mutex));
		time_in_ms = go_to_sleep(philo);
	}
	return (NULL);
}

int eat_check(t_philo *philo, int philo_count, int *i, int *hmpem)
{
	if (*i == philo_count - 1)
	{
		if (*hmpem == (philo_count - 1)
			&& philo[0].info.max_eat != -1)
			{
				printf(GREEN "All philosophers have eaten enough\n" RESET);
				return (0);
			}
		*i = 0;
		*hmpem = 0;
	}
		return (1);
}

int death_check(t_philo *philo, int philo_count, struct timeval start_time)
{
	int	i;
	int	how_many_philo_eat_max;

	i = 0;
	how_many_philo_eat_max = 0;
	while (1)
	{
		pthread_mutex_lock(&(philo[i].last_time_mutex));
		if (get_time(start_time) - philo[i].last_time_eaten >= philo[i].info.time_to_die)
		{
			printf(RED "%d philo {%d} died from starving\n" RESET, get_time(start_time), philo->id);
			return (1);
		}
		if (philo[i].eat_count >= philo[i].info.max_eat)
			how_many_philo_eat_max++;
		pthread_mutex_unlock(&(philo[i].last_time_mutex));
		if (eat_check(philo, philo_count, &i, &how_many_philo_eat_max) == 0)
			return (0);
		i++;
	}
	return (0);
}


int main(int argc, char **argv)
{
    pthread_mutex_t *forks;
    t_philo         *philo;
    t_const         consts;

    parsing(argc, argv);
    consts.i = 0;
    gettimeofday(&consts.start_time, NULL);
    consts.philo_count = ft_atoi(argv[1]);
    forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * consts.philo_count);
    philo = (t_philo *)malloc(sizeof(t_philo) * consts.philo_count); 
    init_mutexes(forks, philo, consts.philo_count);
    init_args(forks, philo, consts, argv);
    init_threads(philo);
	death_check(philo, consts.philo_count, consts.start_time);
    return (0);
}
 