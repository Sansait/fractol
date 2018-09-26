/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:56:52 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/25 19:40:36 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_data *d, char *av)
{
	d->zoom = 1;
	d->av = ft_strdup(av);
	d->i_max = 1000;
	d->r = 10;
	d->g = 10;
	d->b = 10;
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
	init(d, av[1]);
//	w_fractal(d);
	d->mlx->m_ptr = mlx_init();
	d->mlx->w_ptr = mlx_new_window(d->mlx->m_ptr, WIDTH, HEIGHT, "fractol");
	d->mlx->i_ptr = mlx_new_image(d->mlx->m_ptr, WIDTH, HEIGHT);
	d->mlx->img = (int*)mlx_get_data_addr(d->mlx->i_ptr, &osef, &osef, &osef);
	centraldisp(d);
	mlx_do_key_autorepeaton(d->mlx->m_ptr);
	mlx_hook(d->mlx->w_ptr, 2, osef, key_press, d);
	mlx_hook(d->mlx->w_ptr, 4, osef, mouse_press, d);
	mlx_loop(d->mlx->m_ptr);
	return (0);
}