/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:50:02 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/24 15:13:36 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_data
{
	char	**numbers;
	int		argv_len;
	int		size_arr;
	int		*arr_index1;
}	t_data;

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

int				ft_atoi(const char *str);
void			ft_atoi_helper(int *i, int output, const char *str, int *k);
int				ft_atoi2(const char *str, int *i, int *k);
char			**ft_split(char *s, char c, int *count);
int				the_length_of_argv(int argc, char **argv);
char			*ft_strcpy(char *dest, char *src, int *i, int argv_len);
void			ft_bzero(void *s, int n);
size_t			ft_wordcount(char *s, char c);
size_t			ft_wordlength(char *s, char c, int k);
size_t			ft_strlen(const char *s);
int				find_min(t_list **a);
int				find_max(t_list **a);
int				n(int len);
void			for_error(void);
void			special_cases(int *arr, int arr_size);
void			space_checker(char *argv);
int				arr_len(char *mix);
void			a_is_sorted(int *arr, int size_arr);
t_list			*ft_lstnew(int data);
t_list			*ft_lstlast(t_list *lst);
void			quick_sort(int *arr, int size_arr);
int				*for_index_sort(int *arr, int *arr1, int *arr_index,
					int size_arr);
void			sa(t_list **lst, int flag);
void			sb(t_list **lst, int flag);
void			pa(t_list **a, t_list **b);
void			pb(t_list **a, t_list **b);
void			ra(t_list **a, int flag);
void			rb(t_list **b, int flag);
void			rra(t_list **a, int flag);
void			rrb(t_list **b, int flag);
void			rrr(t_list **a, t_list **b);
void			rr(t_list **a, t_list **b);
void			ss(t_list **a, t_list **b);
void			butterfly(t_list **a, t_list **b, int size_arr);
void			back_to_a(t_list **a, t_list **b, int size_arr);
void			for_special_case(t_list **a, t_list **b,
					int size_arr);
void			for_3greater(t_list **a, t_list **b,
					int size_arr);
char			**mix(int argv_len, int argc, char **argv, int *size_arr);
int				*arr_index(int size_arr, char **numbers);

#endif
