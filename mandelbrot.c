/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:41:23 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/28 14:54:43 by sklepper         ###   ########.fr       */
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
	double x;
	double y;
	double c_re;
	double c_im;

	x = mlx->x_min;
	y = mlx->y_min;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			c_re = (x - (WIDTH / mlx->zoom) / 2.0) * 4.0 / (WIDTH / mlx->zoom);
			c_im = (y - (HEIGHT / mlx->zoom) / 2.0) * 4.0 / (WIDTH / mlx->zoom);
			mlx->img[y * WIDTH + x] = mandelbrot(c_re, c_im, mlx);
			x++;
		}
		x = 0;
		y++;
	}
}
