/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 16:48:41 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/16 16:48:44 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_win	*new_picture(t_win *win)
{
	if ((win->pixel = mlx_new_image(win->init, 1024, 1024)) == NULL)
	{
		write(1, "Ошибка: picture, строчка 21\n", 28);
		return (NULL);
	}
	win->color_value = 1;
	win->zoom = 0.7;
	win->move_y = 0;
	dop_pict(win);
	win->option_y = 1;
	win->option_x = 1;
	win->max_iter = 180;
	win->ptr = mlx_get_data_addr(win->pixel, &win->w, &win->stride, &win->end);
	win->w /= 8;
	win->change_julia = 1;
	win->x = 0;
	win->y = 0;
	win->y_max = 0;
	return (win);
}

void	plus_or_minus(t_win *win, int key)
{
	if (key == 69)
	{
		win->zoom = win->zoom * 1.2;
		win->max_iter += 10;
	}
	else
		win->zoom = win->zoom / 1.2;
	open_frac(win);
}

void	col_of_iter(t_win *win, int key)
{
	if (key == 24)
		win->max_iter += 10;
	else
	{
		if (win->max_iter - 10 > 0)
			win->max_iter -= 10;
	}
	open_frac(win);
}

void	shift(t_win *win, int key)
{
	if (key == 123)
		win->move_x -= 0.1 / win->zoom;
	else if (key == 124)
		win->move_x += 0.1 / win->zoom;
	else if (key == 125)
		win->move_y += 0.1 / win->zoom;
	else if (key == 126)
		win->move_y -= 0.1 / win->zoom;
	open_frac(win);
}

void	with_start(t_win *win)
{
	win->color_value = 1;
	win->zoom = 0.7;
	win->move_y = 0;
	dop_pict(win);
	win->option_y = 1;
	win->option_x = 1;
	win->max_iter = 180;
	win->ptr = mlx_get_data_addr(win->pixel, &win->w, &win->stride, &win->end);
	win->w /= 8;
	win->change_julia = 1;
	win->x = 0;
	win->y = 0;
	win->y_max = 0;
	open_frac(win);
}
