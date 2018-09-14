/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:45:18 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/14 10:30:15 by sklepper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# include <math.h>
# include "mlx.h"
# include "libft/includes/libft.h"

# define WIDTH		800
# define HEIGHT		600
# define KEY_ESC	53

# define SCROLL_UP		4
# define SCROLL_DOWN	5

struct	s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*img;

};

typedef struct s_data	t_data;

int			key_press(int key, t_data *data);
int			mouse_press(int b, int x, int y, t_data *data);


#endif