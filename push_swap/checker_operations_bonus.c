/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:21:18 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/19 18:23:39 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa_c(t_list **lst)
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
}

void	sb_c(t_list **lst)
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
}

void	ss_c(t_list **a, t_list **b)
{
	sa_c(a);
	sb_c(b);
}

void	pa_c(t_list **a, t_list **b)
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
}

void	pb_c(t_list **a, t_list **b)
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
}
