/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:04:24 by anmanuky          #+#    #+#             */
/*   Updated: 2023/09/23 15:09:04 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fractol.h"

void	call_jul_helper(t_fractol *var)
{
	var->win = mlx_new_window(var->mlx, LEN, WID, "Julia");
	mlx_hook(var->win, 2, 1L << 0, for_esc_and_arrows, var);
	mlx_hook(var->win, 17, 0L, for_red_cross, var);
	mlx_hook(var->win, 4, 0L, for_mouse_move_j, var);
	var->img.img = mlx_new_image(var->mlx, LEN, WID);
	var->img.addr = mlx_get_data_addr(var->img.img, &(var->img.bits_per_pixel),
			&(var->img.line_length), &(var->img.endian));
}

void	call_man(t_fractol *var)
{
	var->mlx = mlx_init();
	var->min_r = -2.0;
	var->max_r = 1.0;
	var->min_i = -1.5;
	var->max_i = var->min_i + (var->max_r - var->min_r) * LEN / WID;
	var->win = mlx_new_window(var->mlx, LEN, WID, "Mandelbrot");
	mlx_hook(var->win, 2, 1L << 0, for_esc_and_arrows, var);
	mlx_hook(var->win, 17, 0L, for_red_cross, var);
	mlx_hook(var->win, 4, 0L, for_mouse_move_m, var);
	var->img.img = mlx_new_image(var->mlx, LEN, WID);
	var->img.addr = mlx_get_data_addr(var->img.img, &(var->img.bits_per_pixel),
			&(var->img.line_length), &(var->img.endian));
	coordinates_m(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	mlx_loop(var->mlx);
}

void	call_jul(t_fractol *var, int argc, char **argv)
{
	var->mlx = mlx_init();
	var->min_r = -2.0;
	var->max_r = 1.0;
	var->min_i = -1.5;
	var->max_i = var->min_i + (var->max_r - var->min_r) * LEN / WID;
	if (argc == 3)
	{
		var->kr = ft_atof(argv[2]);
		var->ki = 0.156;
	}
	else if (argc == 4)
	{
		var->kr = ft_atof(argv[2]);
		var->ki = ft_atof(argv[3]);
	}
	else
	{
		var->kr = -0.8;
		var->ki = 0.156;
	}
	call_jul_helper(var);
	coordinates_j(var);
	mlx_put_image_to_window(var->mlx, var->win, var->img.img, 0, 0);
	mlx_loop(var->mlx);
}

void	choose(void)
{
	ft_putendl_fd("Which fractol do you prefer?", 1);
	ft_putendl_fd("1-Mandelbrot", 1);
	ft_putendl_fd("2-Julia", 1);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_fractol	var;

	if (argc == 1)
		choose();
	else if (argc > 1)
	{
		if (argc >= 5 || (argc >= 3
				&& (argv[1][0] == '1' && argv[1][1] == '\0')))
			choose();
		if (argv[1][0] == '1' && argv[1][1] == '\0')
			call_man(&var);
		else if (argv[1][0] == '2' && argv[1][1] == '\0')
		{
			call_jul(&var, argc, argv);
		}
		else
			choose();
	}
}
