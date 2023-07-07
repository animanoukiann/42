/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:26:01 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/06 17:55:58 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	partition(int *arr, int i, int j)
{
	int	small_index;
	int	big_index;
	int	pivot;
	int	k;

	pivot = i;
	small_index = i;
	big_index = i;
	k = i + 1;
	while (k < j)
	{
		if (arr[k] > arr[pivot])
			big_index++;
		if (arr[k] < arr[pivot])
		{
			small_index++;
			swap(&arr[small_index], &arr[k]);
			big_index++;
		}
		k++;
	}
	swap(&arr[pivot], &arr[small_index]);
	pivot = small_index;
	return (small_index);
}

void	quick_sort_1(int *arr, int i, int j)
{
	int	pivot;

	if (i == j)
		return ;
	pivot = partition(arr, i, j);
	quick_sort_1(arr, i, pivot);
	quick_sort_1(arr, pivot + 1, j);
}

void	quick_sort(int *arr, int size_arr)
{
	quick_sort_1(arr, 0, size_arr);
}
