/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 18:43:13 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/07 16:01:04 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	space_checker(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != ' ')
			return ;
		i++;
	}
	for_error();
}

void	check_duplication(int index, int *arr, int arr_size)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < arr_size)
	{
		if (arr[i] == arr[index])
			counter++;
		i++;
	}
	if (counter >= 2)
		for_error();
}

void	checker(int *arr, int arr_size)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		check_duplication(i, arr, arr_size);
		if (!(arr[i] <= 2147483647 && arr[i] >= -2147483648))
			for_error();
		i++;
	}
	a_is_sorted(arr, arr_size);
}

void	a_is_sorted(int *arr, int size_arr)
{
	int	i;

	i = 0;
	while ((i < size_arr - 1) && arr[i] < arr[i + 1])
		i++;
	if (i == size_arr - 1)
		exit(0);
}
