/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:04:36 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/09 12:15:13 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		display(t_data *d)
{
	if (d->render == 1)
	{
		centraldisp(d);
		d->render = 0;
	}
	return (0);
}

void	centraldisp(t_data *d)
{
	d->f_fractol(d->mlx);
	mlx_put_image_to_window(d->mlx->m_ptr, d->mlx->w_ptr, d->mlx->i_ptr, 0, 0);
}
