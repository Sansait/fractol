/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 11:41:23 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/21 14:08:47 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot(int x, int y, t_data *d)
{
	double dx;
	double dx_tmp;
	double dy;
	double c_re = (x - WIDTH / 2.0) * 4.0 / WIDTH;
	double c_im = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
	int i;

	dx = 0;
	dy = 0;
	i = 0;
	while (dx * dx + dy * dy < 4 && i < d->i_max)
	{
		dx_tmp = dx * dx - dy * dy + c_re;
		dy = 2 * dx * dy + c_im;
		dx = dx_tmp;
		i++;
	}
	d->img[(y * WIDTH) + x] = ((255 - i * d->r) << 16) + ((255 - i * d->g) << 8)
									  + (255 - i * d->b);
}



//For each pixel (Px, Py) on the screen, do:
//{
//x0 = scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.5, 1))
//y0 = scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1, 1))
//x = 0.0
//y = 0.0
//iteration = 0
//max_iteration = 1000
//while (x*x + y*y < 2*2  AND  iteration < max_iteration) {
//xtemp = x*x - y*y + x0
//y = 2*x*y + y0
//x = xtemp
//iteration = iteration + 1
//}
//color = palette[iteration]
//plot(Px, Py, color)
//}