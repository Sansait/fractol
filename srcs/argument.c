/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:45:15 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/08 16:28:57 by sklepper         ###   ########.fr       */
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
	else if (ft_strcmp(d->av, " "))
		return ;
	else
	{
		ft_putendl("usage");
		return ;
	}
}
