/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 18:22:34 by anmanuky          #+#    #+#             */
/*   Updated: 2023/07/24 15:22:13 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"
# include "get_next_line.h"

void		checker_c(int *arr, int arr_size);
void		sa_c(t_list **lst);
void		sb_c(t_list **lst);
void		pa_c(t_list **a, t_list **b);
void		pb_c(t_list **a, t_list **b);
void		ra_c(t_list **a);
void		rb_c(t_list **b);
void		rra_c(t_list **a);
void		rrb_c(t_list **b);
void		rr_c(t_list **a, t_list **b);
void		ss_c(t_list **a, t_list **b);
void		rrr_c(t_list **a, t_list **b);
void		operations(char *line, t_list **a, t_list **b);
void		list_part_c(int *arr_index, int size_arr, t_list **a);
int			*arr_index_c(int size_arr, char **numbers);
void		list_helper(t_list **a, t_list **b);
void		for_error_bonus(void);
void		space_checker_bonus(char *argv);
void		check_duplication_bonus(int index, int *arr, int arr_size);
void		is_sorted(t_list **a, t_list **b);
int			length_oper(char *str1, char *str2);
void		ok_ko(int a);

#endif
