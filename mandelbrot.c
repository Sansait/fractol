/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:41:23 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/25 19:39:34 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot(double x, double y, t_data *d)
{
	double dx;
	double dx_tmp;
	double dy;
	int i;

	dx = 0;
	dy = 0;
	i = 0;
	while (dx * dx + dy * dy < 4 && i < d->i_max)
	{
		dx_tmp = dx * dx - dy * dy + x;
		dy = 2 * dx * dy + y;
		dx = dx_tmp;
		i++;
	}
	return((255 - i * d->r) << 16) + ((255 - i * d->g) << 8) + (255 - i * d->b);
}

void	draw_mandelbrot(t_mlx *d)
{
	int x;
	int y;
	double c_re;
	double c_im;

	x = 0;
	y = 0;
	while (y < HEIGHT)
	{
		while (x < WIDTH)
		{
			c_re = (x - WIDTH / 2->0) * 4.0 / WIDTH;
			c_im = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
			d->mlx->img[y * WIDTH + x] = mandelbrot(c_re, c_im, d);
			x++;
		}
		x = 0;
		y++;
	}
}
