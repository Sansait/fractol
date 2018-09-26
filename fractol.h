/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 10:45:18 by sklepper          #+#    #+#             */
/*   Updated: 2018/09/25 19:39:34 by sklepper         ###   ########.fr       */
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

typedef struct	s_mlx
{
	void		*m_ptr;
	void		*w_ptr;
	void		*i_ptr;
	int			*img;
}				t_mlx;

typedef struct	s_data
{
	t_mlx		*mlx;
	double		zoom;
	char		*av;
	int			i_max;
	int			r;
	int			g;
	int			b;
}				t_data;

//typedef struct s_data	t_data;

int			key_press(int key, t_data *data);
int			mouse_press(int b, int x, int y, t_data *data);
void		centraldisp(t_data *data);
void		draw_mandelbrot(t_data *data);
void		w_fractal(t_data *d);


#endif