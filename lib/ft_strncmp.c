/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:19:07 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/16 12:39:56 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	if (n == 0)
		return (0);
	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	i = 0;
	while (i < n - 1 && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}
