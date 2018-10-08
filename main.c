/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:56:52 by sklepper          #+#    #+#             */
/*   Updated: 2018/10/08 16:21:34 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		init(t_data *d, char *av)
{
	d->av = ft_strdup(av);
	if (!(d->mlx = malloc(sizeof(t_mlx))))
		return (0);
	d->julia = 0;
	d->mlx->zoom = 1;
	d->mlx->i_max = 100;
	d->mlx->r = 20;
	d->mlx->g = 10;
	d->mlx->b = 5;
	d->mlx->x_min = 0;
	d->mlx->x_max = WIDTH;
	d->mlx->y_min = 0;
	d->mlx->y_max = HEIGHT;
	d->mlx->x_inc = (d->mlx->x_max - d->mlx->x_min) / WIDTH;
	d->mlx->y_inc = (d->mlx->y_max - d->mlx->y_min) / HEIGHT;
	return (1);
}

int main(int ac, char **av)
{
	t_data		*d;
	int			osef;

	if (ac != 2)
	{
		ft_putendl("usage");
		return (0);
	}
	if (!(d = malloc(sizeof(t_data))))
		return (0);
	if (init(d, av[1]) == 0)
		return (0);
	w_fractal(d);
	d->mlx->m_ptr = mlx_init();
	d->mlx->w_ptr = mlx_new_window(d->mlx->m_ptr, WIDTH, HEIGHT, "fractol");
	d->mlx->i_ptr = mlx_new_image(d->mlx->m_ptr, WIDTH, HEIGHT);
	d->mlx->img = (int*)mlx_get_data_addr(d->mlx->i_ptr, &osef, &osef, &osef);
	centraldisp(d);
	mlx_do_key_autorepeaton(d->mlx->m_ptr);
	mlx_hook(d->mlx->w_ptr, 2, osef, key_press, d);
	mlx_hook(d->mlx->w_ptr, 4, osef, mouse_press, d);
	mlx_hook(d->mlx->w_ptr, 6, osef, mouse_move, d);
	mlx_loop(d->mlx->m_ptr);
	return (0);
}