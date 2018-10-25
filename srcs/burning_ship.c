/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:44:18 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/25 17:26:25 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		ship(double x, double y, t_mlx *mlx)
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
		dy = dy > 0 ? dy : -dy;
		dx = dx_tmp > 0 ? dx_tmp : -dx_tmp;
		i++;
	}
	if (i == mlx->i_max)
		return (0);
	return (((255 - (i * mlx->r) % 255)) << 16) +
	((255 - ((i * mlx->g) % 255)) << 8) + (255 - ((i * mlx->b) % 255));
}

void	draw_ship(t_mlx *mlx)
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
			mlx->img[y * WIDTH + x] = ship(c.x, c.y, mlx);
			x++;
			d.x += mlx->x_inc;
		}
		y++;
		d.y += mlx->y_inc;
	}
}
