/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:25:06 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/08 16:44:17 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia(double x, double y, t_mlx *mlx)
{
	double dx;
	double dx_tmp;
	double dy;
	int i;

	dx = x;
	dy = y;
	i = 0;
	while (dx * dx + dy * dy < 4 && i < mlx->i_max)
	{
		dx_tmp = dx * dx - dy * dy + mlx->c_x;
		dy = 2 * dx * dy + mlx->c_y;
		dx = dx_tmp;
		i++;
	}
	return((255 - ((i * mlx->r) % 255)) << 16) +
	((255 - ((i * mlx->g) % 255)) << 8) + (255 - ((i * mlx->b) % 255));
}

void	draw_julia(t_mlx *mlx)
{
	double	dx;
	double	dy;
	int		x;
	int		y;
	double	c_re;
	double	c_im;


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
			mlx->img[y * WIDTH + x] = julia(c_re, c_im, mlx);
			x++;
			dx += mlx->x_inc;
		}
		y++;
		dy += mlx->y_inc;
	}
}
