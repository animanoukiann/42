/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_unsigned_int.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 17:41:16 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/28 16:32:11 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	tvanshanneri_qanak_u(unsigned int n)
{
	size_t			count;
	unsigned int	skzbnakan;

	count = 0;
	skzbnakan = n;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	if (skzbnakan > 0)
		return (count);
	return (count + 1);
}

void	put_un_nbr(unsigned int n)
{
	if (n > 9)
	{
		put_un_nbr(n / 10);
		put_un_nbr(n % 10);
	}
	else
		ft_putchar_fd((n + 48), 1);
}

int	convert_to_unsigned_int(va_list ap)
{
	unsigned int	n;

	n = va_arg(ap, unsigned int);
	put_un_nbr(n);
	return (tvanshanneri_qanak_u(n));
}
