/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:53:26 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/28 16:27:19 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	tvanshanneri_qanak(int n)
{
	size_t	count;
	int		skzbnakan;

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

int	convert_to_integer(va_list	ap)
{
	int	n;

	n = va_arg(ap, int);
	ft_putnbr_fd(n, 1);
	return (tvanshanneri_qanak(n));
}
