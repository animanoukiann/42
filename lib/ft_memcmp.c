/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:16:55 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/16 12:28:53 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	if (n == 0)
		return (0);
	i = 0;
	str2 = (unsigned char *)s2;
	str1 = (unsigned char *)s1;
	while (str1 && str2 && str1[i] == str2[i] && i < n - 1)
		i++;
	if (str1[i] > str2[i])
		return (str1[i] - str2[i]);
	else if (str1[i] < str2[i])
		return (str1[i] - str2[i]);
	return (0);
}
