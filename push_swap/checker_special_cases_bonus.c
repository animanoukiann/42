/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_special_cases_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:22:07 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/24 15:29:43 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	for_error_bonus(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	space_checker_bonus(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] != ' ')
			return ;
		i++;
	}
	for_error_bonus();
}

void	check_duplication_bonus(int index, int *arr, int arr_size)
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
		for_error_bonus();
}

void	checker_c(int *arr, int arr_size)
{
	int	i;

	i = 0;
	while (i < arr_size)
	{
		check_duplication_bonus(i, arr, arr_size);
		i++;
	}
}

void	rrr_c(t_list **a, t_list **b)
{
	rra_c(a);
	rrb_c(b);
}
