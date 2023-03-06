/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:19:48 by anmanuky          #+#    #+#             */
/*   Updated: 2023/03/01 14:57:16 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_out(const char *str, va_list ap)
{
	int	i;
	int	counter;

	i = 1;
	if (str[i] == 'c')
		counter = convert_to_char(ap);
	if (str[i] == 's')
		counter = convert_to_string(ap);
	if (str[i] == 'p')
		counter = convert_to_pointer(ap);
	if (str[i] == 'd' || str[i] == 'i')
		counter = convert_to_integer(ap);
	if (str[i] == 'u')
		counter = convert_to_unsigned_int(ap);
	if (str[i] == 'x' || str[i] == 'X')
		counter = convert_to_hex(ap, str[i]);
	if (str[i] == '%')
	{
		while (str[i] == '%')
			i++;
		counter = convert_to_percent(i) + i;
	}
	return (counter);
}

void	help_ft_printf(const char *str, int *counter, int *i, va_list ap)
{
	int	tokos;

	if (str[*i + 1] == '%')
	{
		tokos = find_out((str + *i), ap);
		if (tokos % 2 == 0)
		{
			*counter += ((tokos * 2) / 3) / 2;
			*i += ((tokos * 2) / 3) - 1;
		}
		else
		{
			*counter += ((tokos * 2) / 3) / 2;
			tokos++;
			*i += ((tokos * 2) / 3) - 1;
		}
	}
	else
	{
		*counter += find_out((str + *i), ap);
		*i = *i + 1;
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	int		counter;

	i = 0;
	va_start(ap, str);
	counter = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			help_ft_printf(str, &counter, &i, ap);
		}
		else
		{
			write (1, &str[i], 1);
			counter++;
		}
		i++;
	}
	return (counter);
}
