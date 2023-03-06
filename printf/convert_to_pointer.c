/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:36:17 by anmanuky          #+#    #+#             */
/*   Updated: 2023/03/02 11:49:10 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	helper_p(char *str, uintptr_t n, int i, char x)
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

int	convert_to_hex_p(uintptr_t n, char x)
{
	int				rem;
	char			*str;
	int				i;
	char			*rec;

	i = 0;
	str = malloc(39);
	str[helper_p(str, n, i, x)] = '\0';
	rem = ft_strlen(str);
	rec = reverse_str(str);
	ft_putstr_fd(rec, 1);
	free(rec);
	free(str);
	return (rem);
}

int	convert_to_pointer(va_list ap)
{
	uintptr_t	val;

	val = va_arg(ap, uintptr_t);
	write(1, "0", 1);
	write(1, "x", 1);
	return (convert_to_hex_p(val, 'x') + 2);
}
