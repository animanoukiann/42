#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	output;

	i = 0;
	sign = 1;
	output = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		output = output * 10 + str[i] - '0';
		i++;
	}
	return (output * sign);
}

// millisecond = current time - given_time
int	get_time(struct timeval given_time)
{
	struct timeval	current_time;
	int				milliseconds;

	gettimeofday(&current_time, NULL);
	milliseconds = current_time.tv_sec * 1000LL + current_time.tv_usec / 1000
		- (given_time.tv_sec * 1000LL + given_time.tv_usec / 1000);
	return (milliseconds);
}