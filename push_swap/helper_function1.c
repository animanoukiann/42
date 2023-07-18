/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:59:23 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/12 18:51:37 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_checker(char c, int *k, int *flag)
{
	if ((c == '0') && (*flag == 0))
		(*k)++;
	if ((c <= '9' && c >= '0'))
	{
		if (c != '0')
			*flag = 1;
		return (1);
	}
	return (0);
}

void	ft_atoi1(const char *str, int *i, int *sign)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || (str[*i] == ' '))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign *= -1;
		(*i)++;
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	sign;
	int	k;
	int	flag;

	i = 0;
	sign = 1;
	flag = 0;
	ft_atoi1(str, &i, &sign);
	j = i;
	k = j;
	if (str[j] == '\0')
		for_error();
	while (str[j] != '\0')
	{
		if (!number_checker(str[j], &k, &flag))
			for_error();
		j++;
	}
	return (ft_atoi2(str, &i, &k) * sign);
}

size_t	ft_wordcount(char *s, char c)
{
	size_t	count;
	int		word;
	int		i;

	i = 0;
	word = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			word = 0;
		}
		else if (!word)
		{
			word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

size_t	ft_wordlength(char *s, char c, int k)
{
	size_t	len;

	len = 0;
	while (s[k] != '\0' && s[k] != c)
	{
		len++;
		k++;
	}
	return (len);
}
