/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 14:18:03 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/08 14:23:41 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		zoom(int x, int y, t_data *d, int zoom)
{
	double x_mid;
	double y_mid;

	x_mid = d->mlx->x_min + (x * d->mlx->x_inc);
	d->mlx->x_min += ((d->mlx->x_max - d->mlx->x_min) / 10) * zoom;
	d->mlx->x_max -= ((d->mlx->x_max - d->mlx->x_min) / 10) * zoom;
	d->mlx->x_inc = (d->mlx->x_max - d->mlx->x_min) / WIDTH;
	d->mlx->x_min = x_mid - (((float)WIDTH / 2) * d->mlx->x_inc);
	d->mlx->x_max = x_mid + (((float)WIDTH / 2) * d->mlx->x_inc);
	y_mid = d->mlx->y_min + (y * d->mlx->y_inc);
	d->mlx->y_min += ((d->mlx->y_max - d->mlx->y_min) / 10) * zoom;
	d->mlx->y_max -= ((d->mlx->y_max - d->mlx->y_min) / 10) * zoom;
	d->mlx->y_inc = (d->mlx->y_max - d->mlx->y_min) / HEIGHT;
	d->mlx->y_min = y_mid - (((float)HEIGHT / 2) * d->mlx->y_inc);
	d->mlx->y_max = y_mid + (((float)HEIGHT / 2) * d->mlx->y_inc);
	d->mlx->y_mid = y_mid;
	return (0);
}