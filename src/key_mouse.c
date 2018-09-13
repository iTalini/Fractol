/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:50:47 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/14 11:50:51 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		hook_keydown(int key, t_win *win)
{
	(void)win;
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key == 48)
		change_color(win);
	else if (key == 49)
	{
		if (win->change_julia == 1)
			win->change_julia = 0;
		else if (win->change_julia == 0)
			win->change_julia = 1;
	}
	else if (key == 69 || key == 78)
		plus_or_minus(win, key);
	else if (key == 24 || key == 27)
		col_of_iter(win, key);
	else if (key == 51)
		with_start(win);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		shift(win, key);
	else if (key == 18 || key == 19 || key == 20 || key == 21 ||
		key == 23 || key == 22 || key == 26 || key == 28)
		change_fractal(win, key);
	return (0);
}

int		hook_mousemove(int x, int y, t_win *win)
{
	if (x < 0 || x >= 1024 || y < 0 || y >= 1024)
		return (0);
	if (win->num == 0 && win->change_julia == 1)
	{
		win->option_x = x;
		win->option_y = y;
		julia_work(win);
	}
	if (win->num == 4 && win->change_julia == 1)
	{
		win->option_x = x;
		win->option_y = y;
		rubber_work(win);
	}
	return (0);
}

int		mouse_hook(int k, int x, int y, t_win *win)
{
	if (k == 1 || k == 5)
	{
		win->zoom *= 1.03;
		win->move_x += (x - 512) / (10 * win->zoom * 1024);
		win->move_y += (y - 512) / (10 * win->zoom * 1024);
	}
	else if (k == 2 || k == 4)
	{
		win->zoom = win->zoom / 1.03;
		win->move_x -= (x - 512) / (10 * win->zoom * 1024);
		win->move_y -= (y - 512) / (10 * win->zoom * 1024);
	}
	open_frac(win);
	return (0);
}
