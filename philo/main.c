#include "philo.h"

int go_to_eat(t_philo *philo)
{
    int start_eat_time;
    int cur_time;

    start_eat_time = get_time(philo->start_time);
    printf("time: %d philo: %d is eating\n", start_eat_time, philo->id);
    cur_time = get_time(philo->start_time);
    while (cur_time - start_eat_time < philo->info.time_to_eat)
        cur_time = get_time(philo->start_time);
    return (cur_time);
}

int go_to_sleep(t_philo *philo)
{
    int start_sleep_time;
    int cur_time;

    start_sleep_time = get_time(philo->start_time);
    printf("time: %d philo: %d is sleeping\n", start_sleep_time, philo->id);
    cur_time = get_time(philo->start_time);
    while (cur_time - start_sleep_time < philo->info.time_to_sleep)
        cur_time = get_time(philo->start_time);
    printf("time: %d philo: %d is thinking\n", cur_time, philo->id);
    return (cur_time);
}

void changes(t_philo *philo, int time)
{
    philo->last_time_eaten = time;
    philo->eat_count++;
}

void    *thread_hendler(void *arg)
{
    t_philo *philo;
    int     fork_id;
    int     cur_time;

    philo = (t_philo *)arg;
    printf("%d\n", philo->id);
    if (philo->id % 2 != 0)
        usleep(1500);
    while (1)
    {
        cur_time = get_time(philo->start_time);
        fork_id = philo->id - 1 % philo->philo_count;
        if (fork_id < 0)
            fork_id = philo->philo_count - 1;
        pthread_mutex_lock(&(philo->forks[fork_id]));
        printf("time: %d philo: %d has taken his right fork\n", cur_time, philo->id);
        pthread_mutex_lock(&(philo->forks[philo->id + 1 % philo->philo_count]));
        printf("time: %d philo: %d has taken his left fork\n", cur_time, philo->id);
        cur_time = go_to_eat(philo);
        pthread_mutex_unlock(&(philo->forks[fork_id]));
        pthread_mutex_unlock(&(philo->forks[philo->id + 1 % philo->philo_count]));
        pthread_mutex_lock(&(philo->last_time_mutex));
        changes(philo, cur_time);
        pthread_mutex_unlock(&(philo->last_time_mutex));
        cur_time = go_to_sleep(philo);
    }
    return (NULL);
}

int main(int argc, char **argv)
{
    t_args          obj;
    t_philo         *philo;
    t_const         consts;
    pthread_mutex_t *forks;

    consts.i = 0;
    gettimeofday(&consts.start_time, NULL);
    parsing(argc, argv);
    init_args(&obj, argv);
    consts.philo_count = ft_atoi(argv[1]);
    philo = (t_philo *)malloc(sizeof(t_philo) * consts.philo_count);
    forks = malloc(sizeof(pthread_mutex_t) * consts.philo_count);
    init_mutexes(forks, philo, consts.philo_count);
    while (consts.i < consts.philo_count)
    {
        philo[consts.i].start_time = consts.start_time;
        philo[consts.i].forks = forks;
        init_philo(&philo[consts.i], argv, obj, consts.i);
        init_threads(&(philo[consts.i]));
        (consts.i)++;
    }
    return 0;
}