/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:19:17 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/16 18:57:39 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(needle) == 0 || !*needle)
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (ft_strncmp(((char *)haystack + i), needle, ft_strlen(needle)) == 0)
		{
			if (i + ft_strlen(needle) > len)
				return (NULL);
			return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
