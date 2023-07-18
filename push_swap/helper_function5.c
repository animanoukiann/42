/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:47:18 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/12 16:42:46 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi_helper1(int *i, int output, const char *str, int *j)
{
	if ((*i) >= 10 && str[0] == '-')
	{
		if (output >= 214748364 && (*i) == 10)
		{
			if ((str[(*j)] > '8' && output == 214748364) || output > 214748364)
				for_error();
		}
		if ((*i) > 10)
			for_error();
	}
}

void	ft_atoi_helper(int *i, int output, const char *str, int *j)
{
	if ((*i) >= 9 && str[0] != '+' && str[0] != '-')
	{
		if (output >= 214748364 && (*i) == 9)
		{
			if ((str[(*j)] > '7' && output == 214748364) || output > 214748364)
				for_error();
		}
		if ((*i) > 9)
			for_error();
	}
	if ((*i) >= 10 && str[0] == '+')
	{
		if (output >= 214748364 && (*i) == 10)
		{
			if ((str[(*j)] > '7' && output == 214748364) || output > 214748364)
				for_error();
		}
		if ((*i) > 10)
			for_error();
	}
	ft_atoi_helper1(i, output, str, j);
}

int	ft_atoi2(const char *str, int *i, int *k)
{
	int	output;
	int	p;
	int	j;

	output = 0;
	j = 0;
	if (*k >= 2)
	{
		if (str[0] == '+' || str[0] == '-')
			p = 1;
		else
			p = 0;
	}
	else
		p = *i;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		ft_atoi_helper(&p, output, str, &(*i));
		output = output * 10 + str[*i] - '0';
		if (str[*i] != '0' || output != 0)
			p++;
		(*i)++;
	}
	return (output);
}
