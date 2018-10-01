/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 17:45:15 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/25 19:31:32 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	w_fractal(t_data *d)
{
	if (ft_strcmp(d->av, "mandelbrot") == 0)
		d->f_fractol = &draw_mandelbrot;
	if (ft_strcmp(d->av, " "))
		return ;
	if (ft_strcmp(d->av, " "))
		return ;
	else
	{
		ft_putendl("usage");
		return ;
	}
}