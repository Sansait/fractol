/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:18:03 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/08 15:19:54 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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