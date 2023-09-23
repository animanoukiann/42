/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:00:09 by anmanuky          #+#    #+#             */
/*   Updated: 2023/09/16 18:31:18 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"
#include <stdio.h>

void	julia(t_fractol *var, double zr, double zi)
{
	int		count;
	double	temp;

	count = 0;
	while (count < MAX_ITER)
	{
		if ((zr * zr + zi * zi) > 4.0)
			break ;
		temp = zr;
		zr = (zr * zr) - (zi * zi) + var->kr;
		zi = 2 * zi * temp + var->ki;
		count++;
	}
	find_the_color_m(var, count);
}

void	coordinates_j(t_fractol *var)
{
	double	pr;
	double	pi;

	var->y = 0;
	while (var->y <= LEN)
	{
		var->x = 0;
		while (var->x <= WID)
		{
			pr = (double)(var->x) * (var->max_r - var->min_r)
				/ WID + var->min_r;
			pi = (double)(var->y) * (var->max_i - var->min_i)
				/ LEN + var->min_i;
			julia (var, pr, pi);
			(var->x)++;
		}
		(var->y)++;
	}
}
