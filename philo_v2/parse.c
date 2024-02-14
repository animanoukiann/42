#include "philo.h"

void	exit_fail(void)
{
	printf(RED "Something went wrong!\n" RESET);
	exit(1);
}

int	ft_atoi_case(const char *str, int i)
{
	if (str[i] == '\0')
		return (1);
	else
	{
		while (str[i])
		{
			if (str[i] != '\0' && str[i] != ' ')
				return (0);
			i++;
		}
		return (1);
	}
}

int	ft_atoi_changed(const char *str)
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
		if (output > (INT_MAX - (str[i] - '0')) / 10)
			return (0);
		output = output * 10 + str[i] - '0';
		i++;
	}
	if (ft_atoi_case(str, i) == 1 && sign != -1)
		return (output * sign);
	return (0);
}

void	parsing(int argc, char **argv)
{
	int	i;
	if (argc < 5 || argc > 6)
		exit_fail();
	i = 1;
	while (i < argc)
	{
		if (ft_atoi_changed(argv[i]) == 0)
			exit_fail();
		i++;
	}
}