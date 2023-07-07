/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:54:18 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/28 16:13:14 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	convert_to_string(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	if (str == 0)
	{
		write(1, "(", 1);
		write(1, "n", 1);
		write(1, "u", 1);
		write(1, "l", 1);
		write(1, "l", 1);
		write(1, ")", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}
