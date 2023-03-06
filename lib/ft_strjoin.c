/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:14:37 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/16 12:37:42 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*mix;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	mix = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (mix == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		mix[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] != '\0')
	{
		mix[i] = s2[j];
		i++;
		j++;
	}
	mix[i] = '\0';
	return (mix);
}
