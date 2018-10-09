/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:18:03 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/09 11:53:38 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		zoom(int x, int y, t_data *d, int zoom)
{
	double mid_b;
	double mid_a;

	mid_b = d->mlx->x_min + (x * d->mlx->x_inc);
	d->mlx->x_min += ((d->mlx->x_max - d->mlx->x_min) / 10) * zoom;
	d->mlx->x_max -= ((d->mlx->x_max - d->mlx->x_min) / 10) * zoom;
	d->mlx->x_inc = (d->mlx->x_max - d->mlx->x_min) / WIDTH;
	mid_a = d->mlx->x_min + (x * d->mlx->x_inc);
	d->mlx->x_min -= mid_a - mid_b;
	d->mlx->x_max -= mid_a - mid_b;
	mid_b = d->mlx->y_min + (y * d->mlx->y_inc);
	d->mlx->y_min += ((d->mlx->y_max - d->mlx->y_min) / 10) * zoom;
	d->mlx->y_max -= ((d->mlx->y_max - d->mlx->y_min) / 10) * zoom;
	d->mlx->y_inc = (d->mlx->y_max - d->mlx->y_min) / HEIGHT;
	mid_a = d->mlx->y_min + (y * d->mlx->y_inc);
	d->mlx->y_min -= mid_a - mid_b;
	d->mlx->y_max -= mid_a - mid_b;
	return (0);
}

void	reset(t_data *d)
{
	d->mlx->zoom = 1;
	d->mlx->i_max = 100;
	d->mlx->r = 20;
	d->mlx->g = 10;
	d->mlx->b = 5;
	d->mlx->x_min = 0;
	d->mlx->x_max = WIDTH;
	d->mlx->y_min = 0;
	d->mlx->y_max = HEIGHT;
	d->mlx->x_inc = (d->mlx->x_max - d->mlx->x_min) / WIDTH;
	d->mlx->y_inc = (d->mlx->y_max - d->mlx->y_min) / HEIGHT;
}
