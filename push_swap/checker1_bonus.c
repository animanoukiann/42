/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:20:44 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/24 19:32:37 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t				i;
	const unsigned char	*s1;
	const unsigned char	*s2;

	if (n == 0)
		return (0);
	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	i = 0;
	while (i < n - 1 && s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] > s2[i])
		return (1);
	if (s1[i] < s2[i])
		return (-1);
	return (0);
}

void	operations(char *line, t_list **a, t_list **b)
{
	if (!ft_strncmp(line, "sa", length_oper(line, "sa\n")))
		sa_c(a);
	else if (!ft_strncmp(line, "sb", length_oper(line, "sb\n")))
		sb_c(b);
	else if (!ft_strncmp(line, "ss", length_oper(line, "ss\n")))
		ss_c(a, b);
	else if (!ft_strncmp(line, "pa", length_oper(line, "pa\n")))
		pa_c(a, b);
	else if (!ft_strncmp(line, "pb", length_oper(line, "pb\n")))
		pb_c(a, b);
	else if (!ft_strncmp(line, "rr", length_oper(line, "rr\n")))
		rr_c(a, b);
	else if (!ft_strncmp(line, "ra", length_oper(line, "ra\n")))
		ra_c(a);
	else if (!ft_strncmp(line, "rb", length_oper(line, "rb\n")))
		rb_c(b);
	else if (!ft_strncmp(line, "rra", length_oper(line, "rra\n")))
		rra_c(a);
	else if (!ft_strncmp(line, "rrb", length_oper(line, "rrb\n")))
		rrb_c(b);
	else if (!ft_strncmp(line, "rrr", length_oper(line, "rrr\n")))
		rrr_c(a, b);
	else
		for_error_bonus();
}

void	ok_ko(int a)
{
	if (a == 0)
	{
		write(1, "KO\n", 3);
		exit(1);
	}
	else
	{
		write(1, "OK\n", 3);
		exit(0);
	}
}

void	list_helper(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	if (!line)
	{
		is_sorted(a, b);
		ok_ko(1);
		return ;
	}
	operations(line, a, b);
	while (line)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		operations(line, a, b);
	}
	is_sorted(a, b);
	ok_ko(1);
}

void	list_part_c(int *arr_index, int size_arr, t_list **a)
{
	int		i;

	i = 0;
	while (i < size_arr)
	{
		(*a) = ft_lstnew(arr_index[i]);
		if (!(*a))
			break ;
		a = &(*a)->next;
		i++;
	}
	free(arr_index);
}
