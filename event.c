/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:29:53 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/08 14:20:39 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_press(int key, t_data *d)
{
	ft_putnbr(key);
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_PLUS)
		d->mlx->i_max += 10;
	if (key == KEY_MINUS && d->mlx->i_max > 10)
		d->mlx->i_max -= 10;
	centraldisp(d);
	return (0);
}

int			mouse_press(int b, int x, int y, t_data *d)
{
	ft_putnbr(b);
	if (b == SCROLL_UP)
	{
		zoom(x, y, d, 1);
		centraldisp(d);
	}
	else if (b == SCROLL_DOWN && d->mlx->zoom > 1)
	{
		zoom(x, y, d, -1);
		centraldisp(d);
	}
	return (0);
}