/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:40:56 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/20 18:42:28 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	k;

	if (ft_strlen(s) != 0)
		i = ft_strlen(s) - 1;
	else
		i = 0;
	k = (char)c;
	while (s[i] && s[i] != k && i > 0)
		i--;
	if (s[i] == k)
		return ((char *)s + i);
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	return (0);
}
