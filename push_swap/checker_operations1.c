/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:45:38 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/14 16:58:04 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra_c(t_list **a)
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
}

void	rb_c(t_list **b)
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
}

void	rr_c(t_list **a, t_list **b)
{
	ra_c(a);
	rb_c(b);
}

void	rra_c(t_list **a)
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
}

void	rrb_c(t_list **b)
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
}
