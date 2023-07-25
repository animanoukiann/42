/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 18:53:12 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/25 16:32:14 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		space_checker(argv[i]);
		mix = ft_strcpy(mix, argv[i], &j, argv_len);
		i++;
	}
	*size_arr = 0;
	numbers = ft_split(mix, ' ', &(*size_arr));
	free(mix);
	return (numbers);
}

int	*arr_index(int size_arr, char **numbers)
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
	special_cases(arr, size_arr);
	quick_sort(arr, size_arr);
	arr_index = for_index_sort(arr, arr1, arr_index, size_arr);
	free(arr);
	free(arr1);
	return (arr_index);
}

void	list_part(int *arr_index, int size_arr, t_list **a)
{
	int		i;

	i = 0;
	while (i < size_arr)
	{
		(*a) = ft_lstnew(arr_index[i]);
		if (!(*a))
			break ;
		a = &(*a)->next;
		i++;
	}
	free(arr_index);
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
		data->arr_index1 = arr_index(data->size_arr, data->numbers);
		list_part(data->arr_index1, data->size_arr, &a);
		butterfly(&a, &b, data->size_arr);
		back_to_a(&a, &b, data->size_arr);
	}
	return (0);
}
