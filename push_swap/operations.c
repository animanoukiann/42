/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:45:32 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/24 15:07:16 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lst, int flag)
{
	t_list	*start;
	t_list	*cur;

	if (!(*lst) || !((*lst)->next))
		return ;
	start = (*lst)->next;
	(*lst)->next = start->next;
	cur = *lst;
	*lst = start;
	(*lst)->next = cur;
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	sb(t_list **lst, int flag)
{
	t_list	*start;
	t_list	*cur;

	if (!(*lst) || !((*lst)->next))
		return ;
	start = (*lst)->next;
	(*lst)->next = start->next;
	cur = *lst;
	*lst = start;
	(*lst)->next = cur;
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	sa(a, 1);
	sb(b, 1);
	write(1, "ss\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*cur;

	if (!(*b))
		return ;
	cur = (*b)->next;
	if (!a)
	{
		*a = *b;
		(*a)->next = NULL;
	}
	(*b)->next = *a;
	*a = *b;
	*b = cur;
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*cur;

	if (!(*a))
		return ;
	cur = (*a)->next;
	if (!b)
	{
		*b = *a;
		(*b)->next = NULL;
	}
	(*a)->next = *b;
	*b = *a;
	*a = cur;
	write(1, "pb\n", 3);
}
