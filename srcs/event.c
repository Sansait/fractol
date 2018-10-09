/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:29:53 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/09 11:57:09 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			key_press(int key, t_data *d)
{
	ft_putnbr(key);
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_PLUS)
		d->mlx->i_max += 10;
	if (key == KEY_MINUS && d->mlx->i_max > 10)
		d->mlx->i_max -= 10;
	if (key == KEY_SPACE)
		d->julia_p = (d->julia_p == 0) ? 1 : 0;
	if (key == KEY_R)
		reset(d);
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
	else if (b == SCROLL_DOWN)
	{
		zoom(x, y, d, -1);
		centraldisp(d);
	}
	return (0);
}

int			mouse_move(int x, int y, t_data *d)
{
	if (d->julia == 1 && d->julia_p == 1)
	{
		d->mlx->c_x = (x - WIDTH / 2.0) * 4.0 / WIDTH;
		d->mlx->c_y = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
		centraldisp(d);
	}
	return (0);
}
