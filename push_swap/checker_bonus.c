/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:20:54 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/19 18:23:28 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	length_oper(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str1[i] != '\0')
		i++;
	while (str2[j] != '\0')
		j++;
	if (i > j)
		return (i - 1);
	else
		return (j - 1);
}

void	is_sorted(t_list **a, t_list **b)
{
	while (*a && (*a)->next)
	{
		if ((*a)->data < (*a)->next->data)
			*a = (*a)->next;
		else
			ok_ko(0);
	}
	if (*b)
		ok_ko(0);
}

int	*arr_index_c(int size_arr, char **numbers)
{
	int		k;
	int		*arr;
	int		*arr1;
	int		*arr_index;

	k = 0;
	arr = (int *)malloc(sizeof(int) * (size_arr));
	arr1 = (int *)malloc(sizeof(int) * (size_arr));
	arr_index = (int *)malloc(sizeof(int) * (size_arr));
	if (!arr || !arr1 || !arr_index)
		return (0);
	while (k < size_arr)
	{
		arr[k] = ft_atoi(numbers[k]);
		arr1[k] = arr[k];
		k++;
	}
	checker_c(arr, size_arr);
	quick_sort(arr, size_arr);
	arr_index = for_index_sort(arr, arr1, arr_index, size_arr);
	free(arr);
	free(arr1);
	return (arr_index);
}

char	**mix(int argv_len, int argc, char **argv, int *size_arr)
{
	int		i;
	char	**numbers;
	char	*mix;
	int		j;

	mix = (char *)malloc(sizeof(char) * argv_len);
	if (!mix)
		return (0);
	i = 1;
	ft_bzero(mix, argv_len - 1);
	j = 0;
	while (i < argc)
	{
		space_checker_bonus(argv[i]);
		mix = ft_strcpy(mix, argv[i], &j, argv_len);
		i++;
	}
	*size_arr = 0;
	numbers = ft_split(mix, ' ', &(*size_arr));
	free(mix);
	return (numbers);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (argc >= 2)
	{
		a = NULL;
		b = NULL;
		data->argv_len = the_length_of_argv(argc, argv);
		data->numbers = mix(data->argv_len, argc, argv, &data->size_arr);
		data->arr_index1 = arr_index_c(data->size_arr, data->numbers);
		list_part_c(data->arr_index1, data->size_arr, &a);
		list_helper(&a, &b);
	}
	return (0);
}
