/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 19:47:18 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/06 19:47:31 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_atoi_helper1(int *i, int output, const char *str)
{
	if ((*i) >= 10 && str[0] == '-')
	{
		if (output >= 214748364 && (*i) == 10)
		{
			if (str[(*i)] > '8')
				for_error();
		}
		if ((*i) > 10)
			for_error();
	}
}

void	ft_atoi_helper(int *i, int output, const char *str)
{
	if ((*i) >= 9 && str[0] != '+' && str[0] != '-')
	{
		if (output >= 214748364 && (*i) == 9)
		{
			if (str[(*i)] > '7')
				for_error();
		}
		if ((*i) > 9)
			for_error();
	}
	if ((*i) >= 10 && str[0] == '+')
	{
		if (output >= 214748364 && (*i) == 10)
		{
			if (str[(*i)] > '7')
				for_error();
		}
		if ((*i) > 10)
			for_error();
	}
	ft_atoi_helper1(i, output, str);
}
