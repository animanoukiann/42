/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:20:01 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/04 18:58:40 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strcpy(char *dest, char *src, int *i, int argv_len)
{
	int	j;
	int	src_size;

	j = 0;
	src_size = 0;
	while (src[j++] != '\0')
		src_size++;
	j = 0;
	if (src[j] == ' ')
		j++;
	while (src[j] != '\0')
	{
		if (j == (src_size - 1) && src[j] == ' ')
			break ;
		dest[(*i)++] = src[j++];
	}
	if (*i != argv_len - 1)
		dest[(*i)++] = ' ';
	dest[*i] = '\0';
	return (dest);
}

int	arr_len(char *mix)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (mix[i] != '\0')
	{
		if (mix[i] == ' ')
			counter++;
		i++;
	}
	return (counter + 1);
}

void	ft_bzero(void *s, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (s[i - 1] == ' ')
		i--;
	if (s[0] == ' ')
		i--;
	return (i);
}

int	the_length_of_argv(int argc, char **argv)
{
	int	size;
	int	i;

	i = 1;
	size = 0;
	while (i < argc)
	{
		size += ft_strlen(argv[i]);
		size++;
		i++;
	}
	return (size);
}
