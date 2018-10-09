/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:41:23 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/09 11:34:01 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		mandelbrot(double x, double y, t_mlx *mlx)
{
	double	dx;
	double	dx_tmp;
	double	dy;
	int		i;

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
	return (((255 - (i * mlx->r) % 255)) << 16) +
	((255 - ((i * mlx->g) % 255)) << 8) + (255 - ((i * mlx->b) % 255));
}

void	draw_mandelbrot(t_mlx *mlx)
{
	t_double	d;
	t_double	c;
	int			x;
	int			y;

	d.y = mlx->y_min;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		d.x = mlx->x_min;
		while (x < WIDTH)
		{
			c.x = (d.x - WIDTH / 2.0) * 4.0 / WIDTH;
			c.y = (d.y - HEIGHT / 2.0) * 4.0 / WIDTH;
			mlx->img[y * WIDTH + x] = mandelbrot(c.x, c.y, mlx);
			x++;
			d.x += mlx->x_inc;
		}
		y++;
		d.y += mlx->y_inc;
	}
}
