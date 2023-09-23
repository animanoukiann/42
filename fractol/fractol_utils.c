/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:58:19 by anmanuky          #+#    #+#             */
/*   Updated: 2023/09/23 15:09:14 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof_helper(char *str, t_atof *var)
{
	if (str[var->i] == '.')
	{
		var->i++;
		var->j = 0;
		var->output2 = 0;
		while (str[var->i] >= '0' && str[var->i] <= '9')
		{
			var->output2 = var->output2 * 10 + str[var->i] - '0';
			var->j++;
			var->i++;
			if (var->j > 6)
				break ;
		}
		if (str[var->i] >= '0' && str[var->i] <= '9')
		{
			if (str[var->i] >= '5')
				var->output2++;
		}
		while (var->j--)
			var->sub *= 10;
		var->output1 += var->output2 / var->sub;
	}
	return (var->output1 * var->sign);
}

double	ft_atof(char *str)
{
	t_atof	var;

	var.i = 0;
	var.sign = 1;
	var.output1 = 0;
	var.sub = 1;
	while ((str[var.i] >= 9 && str[var.i] <= 13) || str[var.i] == ' ')
		var.i++;
	if (str[var.i] == '+' || str[var.i] == '-')
	{
		if (str[var.i] == '-')
			var.sign *= -1;
		var.i++;
	}
	while (str[var.i] >= '0' && str[var.i] <= '9' && str[var.i] != '.')
	{
		var.output1 = var.output1 * 10 + str[var.i] - '0';
		var.i++;
	}
	if (str[var.i] != '.')
		return (var.output1 * var.sign);
	return (ft_atof_helper(str, &var));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	for_esc_and_arrows(int keycode, t_fractol *var)
{
	double	distance;

	distance = 0.2;
	if (keycode == 53)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	else if (keycode == 124)
	{
		var->min_r += (var->max_r - var->min_r) * distance;
		var->max_r += (var->max_r - var->min_r) * distance;
	}
	else if (keycode == 123)
	{
		var->min_r -= (var->max_r - var->min_r) * distance;
		var->max_r -= (var->max_r - var->min_r) * distance;
	}
	return (0);
}

int	for_red_cross(t_fractol *var)
{
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
	return (0);
}
