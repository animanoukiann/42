/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:02:23 by anmanuky          #+#    #+#             */
/*   Updated: 2023/09/18 17:15:24 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	find_color_helper(int count, int *r, int *g, int *b)
{
	double	t;

	if (count < MAX_ITER / 2)
	{
		t = (double)count / (MAX_ITER / 2);
		*r = 0x00;
		*g = (int)(t * 255);
		*b = (int)(t * 255);
	}
	else
	{
		t = (double)(count - MAX_ITER / 2) / (MAX_ITER / 2);
		*r = (int)(t * 255);
		*g = 0xff;
		*b = 0xff;
	}
}

void	find_the_color_m(t_fractol *var, int count)
{
	int		r;
	int		g;
	int		b;

	if (count == MAX_ITER)
		my_mlx_pixel_put(&(var->img), var->x, var->y, 0x000000);
	else
	{
		find_color_helper(count, &r, &g, &b);
		my_mlx_pixel_put(&(var->img), var->x, var->y, ((r << 16)
				| (g << 8) | b));
	}
}

void	mandelbrot(t_fractol *var, double cr, double ci)
{
	int		count;
	int		flag;
	double	zi;
	double	zr;
	double	temp;

	flag = 1;
	count = 0;
	zi = 0;
	zr = 0;
	while (count < MAX_ITER)
	{
		if ((zr * zr + zi * zi) > 4.0)
		{
			flag = 0;
			break ;
		}
		temp = zr;
		zr = (zr * zr) - (zi * zi) + cr;
		zi = 2 * zi * temp + ci;
		count++;
	}
	find_the_color_m(var, count);
}

void	coordinates_m(t_fractol	*var)
{
	double	cr;
	double	ci;

	var->y = 0;
	while (var->y <= LEN)
	{
		var->x = 0;
		while (var->x <= WID)
		{
			cr = (double)(var->x) * (var->max_r - var->min_r)
				/ WID + var->min_r;
			ci = (double)(var->y) * (var->max_i - var->min_i)
				/ LEN + var->min_i;
			mandelbrot(var, cr, ci);
			(var->x)++;
		}
		(var->y)++;
	}
}
