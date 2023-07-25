/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_function3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:17:33 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/24 15:18:46 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	butterfly_helper(t_list **a, t_list **b)
{
	pb(a, b);
	rb(b, 0);
}

void	butterfly(t_list **a, t_list **b, int size_arr)
{
	int	i;

	i = 0;
	if (!(*a) || !(a) || !(b))
		return ;
	while (*a)
	{
		if (size_arr >= 2 && size_arr <= 5)
		{
			for_special_case(a, b, size_arr);
			return ;
		}
		if ((*a)->data <= i)
		{
			butterfly_helper(a, b);
			i++;
		}
		else if ((*a)->data <= i + n(size_arr))
		{
			pb(a, b);
			i++;
		}
		else
			ra(a, 0);
	}
}

void	for_3(t_list **a)
{
	if (*a)
	{
		if ((*a)->data > (*a)->next->data)
		{
			if ((*a)->next->data < (*a)->next->next->data
				&& (*a)->data > (*a)->next->next->data)
			{
				ra(a, 0);
				return ;
			}
			sa(a, 0);
		}
		if ((*a)->data < (*a)->next->data
			&& (*a)->next->data < (*a)->next->next->data)
			return ;
		rra(a, 0);
		if ((*a)->data > (*a)->next->data)
		{
			sa(a, 0);
		}
	}
}

int	find_min(t_list **a)
{
	int		min;
	int		min_place;
	int		cur_place;
	t_list	*temp;

	min = INT_MAX;
	min_place = 0;
	cur_place = 0;
	temp = *a;
	while (temp)
	{
		if (temp->data < min)
		{
			min = temp->data;
			min_place = cur_place + 1;
		}
		temp = temp->next;
		cur_place++;
	}
	return (min_place);
}

void	for_special_case(t_list **a, t_list **b, int size_arr)
{
	if (size_arr == 2)
	{
		sa(a, 0);
		return ;
	}
	else if (size_arr == 3)
	{		
		for_3(a);
		return ;
	}
	else
	{
		for_3greater(a, b, size_arr);
		for_3(a);
		while (*b)
		{
			pa(a, b);
		}
		return ;
	}
}
