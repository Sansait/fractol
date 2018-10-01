/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:29:53 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/28 14:54:06 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_press(int key, t_data *d)
{
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

int			mouse_press(int b, int x, int y, t_data *d)
{
	if (b == SCROLL_UP)
	{
		d->mlx->zoom *= 1.1;
		d->mlx->ax = (x - ((float)WIDTH / 2)) * (1 / d->mlx->zoom);
		d->mlx->ay = (y - ((float)HEIGHT / 2)) * (1 / d->mlx->zoom);
		centraldisp(d);
	}
	else if (b == SCROLL_DOWN && d->mlx->zoom > 0.1)
	{
		d->mlx->zoom /= 1.1;
		centraldisp(d);
	}
	return (0);
}