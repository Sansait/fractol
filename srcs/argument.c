/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:45:15 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/09 14:03:47 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	w_fractal(t_data *d)
{
	if (ft_strcmp(d->av, "mandelbrot") == 0)
		d->f_fractol = &draw_mandelbrot;
	else if (ft_strcmp(d->av, "julia") == 0)
	{
		d->f_fractol = &draw_julia;
		d->julia = 1;
		d->julia_p = 1;
	}
	else if (ft_strcmp(d->av, "ship") == 0)
	{
		d->f_fractol = &draw_ship;
		d->mlx->y_min -= d->mlx->y_inc * 100;
		d->mlx->y_max -= d->mlx->y_inc * 100;
	}
	else
	{
		ft_putendl("usage");
		exit (0);
	}
}
