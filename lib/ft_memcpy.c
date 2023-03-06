/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:17:23 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/16 12:29:16 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	size_t		i;
	char		*dst;
	const char	*sorc;

	if (dest == NULL && src == NULL)
		return (NULL);
	dst = (char *)dest;
	sorc = (const char *)src;
	i = 0;
	while (i < len)
	{
		dst[i] = sorc[i];
		i++;
	}
	return ((void *)dest);
}
