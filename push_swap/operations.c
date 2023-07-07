/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:45:32 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/05 19:12:03 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **lst)
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
	ft_printf("sa\n");
}

void	sb(t_list **lst)
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
	ft_printf("sb\n");
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
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
	ft_printf("pa\n");
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
	ft_printf("pb\n");
}
