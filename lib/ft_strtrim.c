/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:43:11 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/21 15:55:44 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*str;
	size_t	skizb;
	size_t	avart;
	size_t	len;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	skizb = i;
	if (skizb == ft_strlen(s1))
		skizb = 1;
	if (ft_strlen(s1) != 0)
		i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i]) != NULL && i > 0)
		i--;
	avart = i;
	len = avart - skizb + 1;
	str = ft_substr(s1, (unsigned int)skizb, len);
	if (str)
		return (str);
	return (NULL);
}
