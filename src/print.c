/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 14:36:39 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/16 14:36:41 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_config(t_win *map)
{
	char	*text;
	char	*nb;

	nb = ft_itoa(map->max_iter);
	text = ft_strjoin("iterations : ", nb);
	mlx_string_put(map->init, map->wi, 10, 10, 0xFFFFFF, text);
	ft_strdel(&text);
	ft_strdel(&nb);
}

void	dop_pict(t_win *win)
{
	if (win->num == 0 || win->num == 4 ||
		win->num == 5 || win->num == 3)
	{
		win->zoom = 0.5;
		win->move_x = 0;
	}
	else if (win->num == 1)
	{
		win->zoom = 0.8;
		win->move_x = -0.5;
	}
	else if (win->num == 2)
	{
		win->move_x = -1.05;
		win->move_y = 0.5;
	}
	else if (win->num == 6)
	{
		win->move_x = -0.15;
		win->move_y = 0;
	}
	else
		win->move_x = 0;
}

void	change_fractal(t_win *win, int key)
{
	if (key == 18)
		win->num = 0;
	else if (key == 19)
		win->num = 1;
	else if (key == 20)
		win->num = 2;
	else if (key == 21)
		win->num = 3;
	else if (key == 23)
		win->num = 4;
	else if (key == 22)
		win->num = 5;
	else if (key == 26)
		win->num = 6;
	else if (key == 28)
		win->num = 7;
	with_start(win);
}
