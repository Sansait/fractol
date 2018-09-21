/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:04:36 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/14 12:04:54 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	centraldisp(t_data *d)
{
	mlx_clear_window(d->mlx_ptr, d->win_ptr);
	ft_bzero(d->img, (WIDTH * HEIGHT * 4));
	draw(d);
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, d->img_ptr, 0, 0);
}