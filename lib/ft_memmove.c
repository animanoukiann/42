/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:17:41 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/20 13:06:17 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	help_memmove(char *dest_1, size_t len, const char *src_1)
{
	while (len)
	{
		dest_1[len - 1] = *src_1;
		len--;
		src_1--;
	}
}

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	char		*dest_1;
	const char	*src_1;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	src_1 = (const char *)src + len - 1;
	dest_1 = (char *)dest;
	if (dest > src)
	{
		help_memmove(dest_1, len, src_1);
	}
	else
	{
		i = 0;
		src_1 = (const char *)src;
		while (i < len)
		{
			dest_1[i] = src_1[i];
			i++;
		}
	}
	return ((void *)dest);
}
