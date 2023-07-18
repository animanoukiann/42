/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:41:26 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/18 18:57:53 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*mix;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	mix = (char *) malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
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
	free(s1);
	return (mix);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	size_t			size;

	if (!s)
		return (NULL);
	size = ft_strlen_gnl(s);
	if ((size_t)start > size)
		len = 0;
	else if (start + len > size)
		len = size - start;
	str = (char *) malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	find_nl(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0' && s)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
