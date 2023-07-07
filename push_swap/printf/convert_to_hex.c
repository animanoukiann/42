/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:25:35 by anmanuky          #+#    #+#             */
/*   Updated: 2023/03/01 14:08:01 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*reverse_str(char *str)
{
	int		i;
	int		j;
	char	*rev;

	rev = malloc(ft_strlen(str) + 1);
	i = ft_strlen(str) - 1;
	j = 0;
	while (i != 0)
	{
		rev[j] = str[i];
		i--;
		j++;
	}
	rev[j++] = str[0];
	rev[j] = '\0';
	return (rev);
}

char	help_hex(int rem)
{
	char	result;

	if (rem == 10)
		result = 'a';
	if (rem == 11)
		result = 'b';
	if (rem == 12)
		result = 'c';
	if (rem == 13)
		result = 'd';
	if (rem == 14)
		result = 'e';
	if (rem == 15)
		result = 'f';
	return (result);
}

char	help_hex_u(int rem)
{
	char	result;

	if (rem == 10)
		result = 'A';
	if (rem == 11)
		result = 'B';
	if (rem == 12)
		result = 'C';
	if (rem == 13)
		result = 'D';
	if (rem == 14)
		result = 'E';
	if (rem == 15)
		result = 'F';
	return (result);
}

int	helper(char *str, unsigned int n, int i, char x)
{
	int	rem;

	if (n == 0)
		str[i++] = '0';
	else
	{
		while (n != 0)
		{
			rem = n % 16;
			n /= 16;
			if (rem >= 0 && rem <= 9)
				str[i++] = rem + 48;
			else
			{
				if (x == 'x')
					str[i++] = help_hex(rem);
				else
					str[i++] = help_hex_u(rem);
			}
		}
	}
	return (i);
}

int	convert_to_hex(va_list ap, char x)
{
	unsigned int	n;
	int				rem;
	char			*str;
	int				i;
	char			*rec;

	n = va_arg(ap, unsigned int);
	i = 0;
	str = malloc(16);
	str[helper(str, n, i, x)] = '\0';
	rem = ft_strlen(str);
	rec = reverse_str(str);
	ft_putstr_fd(rec, 1);
	free(rec);
	free(str);
	return (rem);
}
