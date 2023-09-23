/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmanuky <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:10:59 by anmanuky          #+#    #+#             */
/*   Updated: 2023/09/21 15:56:31 by anmanuky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_ITER 80
# define LEN 900
# define WID 900
# define MAX_COLOR 255

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_atof{
	double	output1;
	double	output2;
	int		sign;
	int		i;
	int		j;
	int		sub;
}	t_atof;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fractol{
	void	*mlx;
	void	*win;
	t_data	img;
	double	min_r;
	double	max_r;
	double	max_i;
	double	min_i;
	double	kr;
	double	ki;
	int		x;
	int		y;
}	t_fractol;

double	ft_atof(char *str);
void	coordinates_j(t_fractol *var);
void	julia(t_fractol *var, double zr, double zi);
void	coordinates_m(t_fractol	*var);
void	mandelbrot(t_fractol *var, double cr, double ci);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		for_esc_and_arrows(int keycode, t_fractol *var);
int		for_red_cross(t_fractol *var);
int		for_mouse_move_m(int button, int x, int y, t_fractol *var);
int		for_mouse_move_j(int button, int x, int y, t_fractol *var);
void	find_the_color_m(t_fractol *var, int count);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putendl_fd(const char *s, int fd);

#endif