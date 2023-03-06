/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:18:12 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/16 12:35:35 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	k;
	int		i;

	i = 0;
	k = (char)c;
	while (s[i] && s && s[i] != k)
		i++;
	if (s[i] == k)
		return ((char *)s + i);
	return (NULL);
}
