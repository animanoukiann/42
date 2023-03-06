/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:41:15 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/16 12:13:41 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	helper(int n)
{
	if (n < 0)
		n = -n;
	if (n == -2147483648)
		n = 2147483647;
	return (n);
}

char	helper2(int i, char *str, int skzbnakan)
{
	if (skzbnakan < 0)
		str[i] = '-';
	if (skzbnakan == 0)
		str[i] = 48;
	return (str[i]);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	size_t	current;
	int		skzbnakan;

	skzbnakan = n;
	str = (char *)malloc(tvanshanneri_qanak(n) + 1);
	if (str == NULL)
		return (NULL);
	i = tvanshanneri_qanak(n);
	str[i] = '\0';
	i--;
	n = helper(n);
	while (n != 0)
	{
		current = (n % 10) + 48;
		str[i] = (unsigned char)current;
		i--;
		n /= 10;
	}
	if (skzbnakan < 0 || skzbnakan == 0)
		str[i] = helper2(i, str, skzbnakan);
	if (skzbnakan == -2147483648)
		str[ft_strlen(str) - 1] = '8';
	return (str);
}
