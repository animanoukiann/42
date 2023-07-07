/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:25:03 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/05 19:14:30 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list **a)
{
	int		max;
	int		max_place;
	int		cur_place;
	t_list	*temp;

	max = INT_MIN;
	max_place = 0;
	cur_place = 0;
	temp = *a;
	while (temp)
	{
		if (temp->data > max)
		{
			max = temp->data;
			max_place = cur_place + 1;
		}
		temp = temp->next;
		cur_place++;
	}
	return (max_place);
}

void	for_3greater_helper(t_list **a, int *count)
{
	while ((*count)--)
	{
		rra(a);
	}
}

void	for_3greater(t_list **a, t_list **b, int size_arr)
{
	int	count;
	int	min_place;

	while (size_arr != 3)
	{
		min_place = find_min(a);
		if (min_place > size_arr / 2)
		{
			count = size_arr - min_place + 1;
			for_3greater_helper(a, &count);
		}
		else
		{
			count = min_place - 1;
			while (count--)
			{
				ra(a);
			}
		}
		pb(a, b);
		size_arr--;
	}
}

void	back_to_a1(int *count, t_list **b)
{
	while ((*count)--)
	{
		rrb(b);
	}
}

void	back_to_a(t_list **a, t_list **b, int size_arr)
{
	int	max_place;
	int	count;

	while (*b)
	{
		max_place = find_max(b);
		if (max_place > size_arr / 2)
		{
			count = size_arr - max_place + 1;
			back_to_a1(&count, b);
		}
		else
		{
			count = max_place - 1;
			while (count--)
			{
				rb(b);
			}
		}
		pa(a, b);
		size_arr--;
	}
}
