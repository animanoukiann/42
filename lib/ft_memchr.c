/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:16:28 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/17 18:06:29 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	k;

	i = 0;
	str = (char *)s;
	k = (unsigned char)c;
	while (i < n)
	{
		if (*str == k)
			return ((void *)str);
			i++;
		str++;
	}
	return (NULL);
}
