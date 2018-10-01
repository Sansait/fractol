/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:04:36 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/28 14:21:37 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	centraldisp(t_data *d)
{
	mlx_clear_window(d->mlx->m_ptr, d->mlx->w_ptr);
	ft_bzero(d->mlx->img, (WIDTH * HEIGHT * 4));
	d->f_fractol(d->mlx);
	mlx_put_image_to_window(d->mlx->m_ptr, d->mlx->w_ptr, d->mlx->i_ptr, 0, 0);
}