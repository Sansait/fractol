/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:56:52 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/14 12:23:05 by sklepper         ###   ########.fr       */
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

//	if (ac != 2)
//	{
//		ft_putendl("");
//		return (0);
//	}
	if (!(d = malloc(sizeof(t_data))))
		return (0);
	init(d, av[0]);
	d->mlx_ptr = mlx_init();
	d->win_ptr = mlx_new_window(d->mlx_ptr, WIDTH, HEIGHT, "fractol");
	d->img_ptr = mlx_new_image(d->mlx_ptr, WIDTH, HEIGHT);
	d->img = (int*)mlx_get_data_addr(d->img_ptr, &osef, &osef, &osef);
	centraldisp(d);
	mlx_do_key_autorepeaton(d->mlx_ptr);
	mlx_hook(d->win_ptr, 2, osef, key_press, d);
	mlx_hook(d->win_ptr, 4, osef, mouse_press, d);
	mlx_loop(d->mlx_ptr);
	return (0);
}