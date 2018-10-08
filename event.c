/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:29:53 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/08 14:48:14 by sklepper         ###   ########.fr       */
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
	else if (b == SCROLL_DOWN)
	{
		zoom(x, y, d, -1);
		centraldisp(d);
	}
//	if (b == 1)
//	{
//		d->click_g = 1;
//		d->mouse_last_x = x;
//		d->mouse_last_y = y;
//	}
//	if (b == 2)
//	{
//		d->click_d = 1;
//		d->mouse_last_x = x;
//		d->mouse_last_y = y;
//	}
	return (0);
}

//int			mouse_release(int b, int x, int y, t_data *d)
//{
//	(void)x;
//	(void)y;
//	if (b == 1)
//		d->click_g = 0;
//	if (b == 2)
//		d->click_d = 0;
//	return (0);
//}

//int			mouse_move(int x, int y, t_data *d)
//{
//	float	dx;
//	float	dy;
//
//	if (d->click_d == 1 || d->click_g == 1)
//	{
//		dx = d->mouse_last_x - x;
//		dy = d->mouse_last_y - y;
//		d->mouse_last_y = y;
//		d->mouse_last_x = x;
//	}
//	if (d->click_d == 1)
//	{
//		d->mlx->x_min += dx / 1000;
//		d->mlx->x_max += dx / 1000;
//		centraldisp(d);
//	}
//	if (d->click_g == 1)
//	{
//		d->mid.y -= dy;
//		d->mid.x -= dx;
//		centraldisp(d);
//	}
//	return (0);
//}