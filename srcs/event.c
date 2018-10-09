/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:29:53 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/09 14:05:26 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int			key_press(int key, t_data *d)
{
	ft_putnbr(key);
	if (key == KEY_ESC && (d->render = 1))
		exit(0);
	if (key == KEY_PLUS && (d->render = 1))
		d->mlx->i_max += 10;
	if (key == KEY_MINUS && d->mlx->i_max > 10 && (d->render = 1))
		d->mlx->i_max -= 10;
	if (key == KEY_SPACE && (d->render = 1))
		d->julia_p = (d->julia_p == 0) ? 1 : 0;
	if (key == KEY_R && (d->render = 1))
		reset(d);
	if (key == KEY_UP || key == KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		move(key, d);
	return (0);
}

int			mouse_press(int b, int x, int y, t_data *d)
{
	ft_putnbr(b);
	if (b == SCROLL_UP)
	{
		zoom(x, y, d, 1);
		d->render = 1;
	}
	else if (b == SCROLL_DOWN)
	{
		zoom(x, y, d, -1);
		d->render = 1;
	}
	return (0);
}

int			mouse_move(int x, int y, t_data *d)
{
	if (d->julia == 1 && d->julia_p == 1)
	{
		d->mlx->c_x = (x - WIDTH / 2.0) * 4.0 / WIDTH;
		d->mlx->c_y = (y - HEIGHT / 2.0) * 4.0 / WIDTH;
		d->render = 1;
	}
	return (0);
}
