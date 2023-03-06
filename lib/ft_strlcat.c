/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:18:29 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/16 12:38:02 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_d;

	if (dst == NULL && dstsize == 0)
		return (0);
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	len_d = ft_strlen(dst);
	i = 0;
	while (len_d < dstsize - 1 && src[i])
	{
		dst[len_d] = src[i];
		len_d++;
		i++;
	}
	dst[len_d] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
