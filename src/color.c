/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:49:46 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/16 12:49:48 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	map_color(int iteration, t_win *map)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	if (iteration == map->max_iter)
	{
		map->color = 0x000000;
		return ;
	}
	r = (iteration * 5) * map->color_value;
	g = (255 - (iteration * 10)) * map->color_value;
	b = (255 - (iteration * 2)) * map->color_value;
	map->color = (r << 16) + (g << 8) + b;
}

void	image_set_pixel(t_win *win, int x, int y, int c)
{
	if (x < 0 || x >= 1024 || y < 0 || y >= 1024)
		return ;
	*(int *)(win->ptr + ((x + (y << 10)) * win->w)) = c;
}

void	change_color(t_win *win)
{
	if (win->color_value == 8000)
		win->color_value = 1;
	else if (win->color_value == 1)
		win->color_value = 200;
	else if (win->color_value == 200)
		win->color_value = 51450;
	else if (win->color_value == 51450)
		win->color_value = 706565;
	else if (win->color_value == 706565)
		win->color_value = 13107400;
	else if (win->color_value == 13107400)
		win->color_value = 2631730;
	else if (win->color_value == 2631730)
		win->color_value = 6553861;
	else
		win->color_value = 8000;
	open_frac(win);
}
