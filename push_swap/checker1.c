#include "checker.h"

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
	if (!ft_strncmp(line, "sa", 2))
		sa_c(a);
	else if (!ft_strncmp(line, "sb", 2))
		sb_c(b);
	else if (!ft_strncmp(line, "ss", 2))
		ss_c(a, b);
	else if (!ft_strncmp(line, "pa", 2))
		pa_c(a, b);
	else if (!ft_strncmp(line, "pb", 2))
		pb_c(a, b);
	else if (!ft_strncmp(line, "ra", 2))
		ra_c(a);
	else if (!ft_strncmp(line, "rb", 2))
		rb_c(b);
	else if (!ft_strncmp(line, "rr", 2) && ft_strncmp(line, "rra", 3) && ft_strncmp(line, "rrb", 3))
		rr_c(a, b);
	else if (!ft_strncmp(line, "rra", 2))
		rra_c(a);
	else if (!ft_strncmp(line, "rrb", 2))
		rrb_c(b);
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

void	is_sorted(t_list **a, t_list **b)
{
	if (*a && (*a)->next)
	{
		if ((*a)->data < (*a)->next->data)
			*a = (*a)->next;
		else
			ok_ko(0);
	}
	if (*b)
		ok_ko(0);
}

void	list_helper(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
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
