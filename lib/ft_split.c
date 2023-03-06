/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:54:12 by anmanuky          #+#    #+#             */
/*   Updated: 2023/02/22 15:50:52 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;
	int		word;

	word = 0;
	count = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			word = 0;
		}
		else if (!word)
		{
			word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static size_t	ft_wordlength(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != '\0' && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

void	fill_arr(char **arr, const char *s, char c, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		len = ft_wordlength(s, c);
		arr[i] = malloc(len + 1);
		j = 0;
		while (j < len)
			arr[i][j++] = *(s++);
		arr[i++][j] = '\0';
	}
	arr[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**arr;

	if (!s)
		return (NULL);
	count = ft_wordcount(s, c);
	arr = malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	fill_arr(arr, s, c, count);
	return (arr);
}
