/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:30:48 by anmanuky          #+#    #+#             */
/*   Updated: 2023/11/21 19:30:50 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strjoin(char const *s1, char a, char const *s2)
{
	char	*mix;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	mix = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 2);
	if (mix == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		mix[i] = s1[i];
		i++;
	}
	mix[i++] = a;
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	str = (char *) malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
