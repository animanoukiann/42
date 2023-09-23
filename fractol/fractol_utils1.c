/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:20:40 by anmanuky          #+#    #+#             */
/*   Updated: 2023/09/20 15:10:26 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	for_mouse_move_m(int button, int x, int y, t_fractol *var)
{
	double	a;
	double	b;

	a = 1.04166667;
	b = 0.949999996;
	if (button == 5)
	{
		var->min_i = var->min_i / a;
		var->max_r = var->max_r / a;
		var->min_r = var->min_r / a;
		var->max_i = var->min_i + (var->max_r - var->min_r) * LEN / WID;
		coordinates_m(var);
		mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	}
	if (button == 4)
	{
		var->min_i /= b;
		var->max_r /= b;
		var->min_r /= b;
		var->max_i = var->min_i + (var->max_r - var->min_r) * LEN / WID;
		coordinates_m(var);
		mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	}
	return (x + y);
}

int	for_mouse_move_j(int button, int x, int y, t_fractol *var)
{
	double	a;
	double	b;

	a = 1.04166667;
	b = 0.949999996;
	if (button == 5)
	{
		var->min_i = var->min_i / a;
		var->max_r = var->max_r / a;
		var->min_r = var->min_r / a;
		var->max_i = var->min_i + (var->max_r - var->min_r) * LEN / WID;
		coordinates_j(var);
		mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	}
	if (button == 4)
	{
		var->min_i /= b;
		var->max_r /= b;
		var->min_r /= b;
		var->max_i = var->min_i + (var->max_r - var->min_r) * LEN / WID;
		coordinates_j(var);
		mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	}
	return (x + y);
}

void	ft_putchar_fd(const char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putstr_fd(const char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putendl_fd(const char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
