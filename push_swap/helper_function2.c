/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:56:30 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/24 15:24:05 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_arr(char **arr, char *s, char c, size_t count)
{
	size_t	i;
	size_t	j;
	int		k;
	size_t	len;

	i = 0;
	k = 0;
	while (i < count)
	{
		while (s[k] == c)
			k++;
		len = ft_wordlength(s, c, k);
		arr[i] = malloc(len + 1);
		j = 0;
		while (j < len)
			arr[i][j++] = s[k++];
		arr[i++][j] = '\0';
	}
	arr[i] = NULL;
}

char	**ft_split(char *s, char c, int *count)
{
	char	**arr;

	if (!s)
		return (NULL);
	*count = ft_wordcount(s, c);
	arr = malloc(((*count) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	fill_arr(arr, s, c, *count);
	return (arr);
}

int	*for_index_sort(int *arr, int *arr1, int *arr_index, int size_arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < size_arr)
	{
		j = 0;
		while (j < size_arr)
		{
			if (arr1[i] == arr[j])
				break ;
			j++;
		}
		arr_index[i] = j;
		i++;
	}
	return (arr_index);
}

int	n(int len)
{
	if (len >= 5 && len < 20)
		return (len / 2);
	else if (len >= 20 && len < 50)
		return (len / 4);
	else if (len >= 50 && len < 500)
		return (len / 8);
	else if (len >= 500)
		return (len / 16);
	return (1);
}
