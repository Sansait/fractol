/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:41:23 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/03 12:55:50 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(double x, double y, t_mlx *mlx)
{
	double dx;
	double dx_tmp;
	double dy;
	int i;

	dx = 0;
	dy = 0;
	i = 0;
	while (dx * dx + dy * dy < 4 && i < mlx->i_max)
	{
		dx_tmp = dx * dx - dy * dy + x;
		dy = 2 * dx * dy + y;
		dx = dx_tmp;
		i++;
	}
	return((255 - i * mlx->r) << 16) + ((255 - i * mlx->g) << 8) + (255 - i * mlx->b);
}

void	draw_mandelbrot(t_mlx *mlx)
{
	double	dx;
	double	dy;
	int		x;
	int		y;
	double	c_re;
	double	c_im;

	mlx->x_inc = (mlx->x_max - mlx->x_min) / WIDTH;
	mlx->y_inc = (mlx->y_max - mlx->y_min) / HEIGHT;
	dy = mlx->y_min;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		dx = mlx->x_min;
		while (x < WIDTH)
		{
			c_re = (dx - WIDTH / 2.0) * 4.0 / WIDTH;
			c_im = (dy - HEIGHT / 2.0) * 4.0 / WIDTH;
			mlx->img[y * WIDTH + x] = mandelbrot(c_re, c_im, mlx);
			x++;
			dx += mlx->x_inc;
		}
		y++;
		dy += mlx->y_inc;
	}
}
