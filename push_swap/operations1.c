/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:45:38 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/24 15:10:22 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, int flag)
{
	t_list	*start;
	t_list	*current;
	t_list	*new;

	if (!a || !(*a) || !((*a)->next))
		return ;
	current = ft_lstlast(*a);
	start = (*a)->next;
	(*a)->next = NULL;
	new = *a;
	if (a)
	{
		if (*a)
			current->next = new;
		else
			*a = new;
	}
	*a = start;
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, int flag)
{
	t_list	*start;
	t_list	*current;
	t_list	*new;

	if (!b || !(*b) || !((*b)->next))
		return ;
	current = ft_lstlast(*b);
	start = (*b)->next;
	(*b)->next = NULL;
	new = *b;
	if (b)
	{
		if (*b)
			current->next = new;
		else
			*b = new;
	}
	*b = start;
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	ra(a, 1);
	rb(b, 1);
	write(1, "rr\n", 3);
}

void	rra(t_list **a, int flag)
{
	t_list	*last;
	t_list	*per_last;

	if (!a || !(*a) || !((*a)->next))
		return ;
	per_last = *a;
	last = ft_lstlast(*a);
	while (per_last->next->next)
		per_last = per_last->next;
	per_last->next = NULL;
	last->next = *a;
	*a = last;
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int flag)
{
	t_list	*last;
	t_list	*per_last;

	if (!b || !(*b) || !((*b)->next))
		return ;
	per_last = *b;
	last = ft_lstlast(*b);
	while (per_last->next->next)
		per_last = per_last->next;
	per_last->next = NULL;
	last->next = *b;
	*b = last;
	if (flag == 0)
		write(1, "rrb\n", 4);
}
