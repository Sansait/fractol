/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:29:53 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/14 10:29:53 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			key_press(int key, t_data *data)
{
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

int			mouse_press(int b, int x, int y, t_data *data)
{
	if (b == SCROLL_UP)
	{

	}
	if (b == SCROLL_DOWN)
	{

	}
	return (0);
}