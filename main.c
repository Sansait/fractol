/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:56:52 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/14 11:03:36 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_data		*data;
	int			osef;

//	if (ac != 2)
//	{
//		ft_putendl("");
//		return (0);
//	}
	if (!(data = malloc(sizeof(t_data))))
		return (0);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "fractol");
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->img = (int*)mlx_get_data_addr(data->img_ptr, &osef, &osef, &osef);
	mlx_do_key_autorepeaton(data->mlx_ptr);
	mlx_hook(data->win_ptr, 2, osef, key_press, data);
	mlx_hook(data->win_ptr, 4, osef, mouse_press, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}