/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:01:27 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/14 11:01:30 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int		ft_close(char *s)
{
	if (s != NULL)
		ft_putstr(s);
	else
	{
		write(1, "Invalid arguments: you must choose one of this", 46);
		write(1, " options: Julia/Mandelbrot/Spider/Four/", 39);
		write(1, "Rubber/Burningship/Biomorph/Mandelbar.\n", 39);
	}
	return (0);
}

int		win_num(char *s)
{
	if (ft_strcmp(s, "Julia") == 0)
		return (0);
	else if (ft_strcmp(s, "Mandelbrot") == 0)
		return (1);
	else if (ft_strcmp(s, "Spider") == 0)
		return (2);
	else if (ft_strcmp(s, "Four") == 0)
		return (3);
	else if (ft_strcmp(s, "Rubber") == 0)
		return (4);
	else if (ft_strcmp(s, "Burningship") == 0)
		return (5);
	else if (ft_strcmp(s, "Biomorph") == 0)
		return (6);
	else if (ft_strcmp(s, "Mandelbar") == 0)
		return (7);
	else
		return (-1);
}

void	open_frac(t_win *win)
{
	if (win->num == 0)
		julia_work(win);
	else if (win->num == 1)
		mandel_work(win);
	else if (win->num == 2)
		spider_work(win);
	else if (win->num == 3)
		four_work(win);
	else if (win->num == 4)
		rubber_work(win);
	else if (win->num == 5)
		burningship_work(win);
	else if (win->num == 6)
		bio_work(win);
	else
		mandelbar_work(win);
}

int		make_win(char *s)
{
	t_win *win;

	if (!(win = ft_memalloc(sizeof(t_win))))
		return (0);
	if ((win->num = win_num(s)) == -1)
	{
		write(1, "Invalid arguments: you must choose one of this", 46);
		write(1, " options: Julia/Mandelbrot/Spider/Four/", 39);
		write(1, "Rubber/Burningship/Biomorph/Mandelbar.\n", 39);
		return (-1);
	}
	if (!(win->init = mlx_init()))
		return (0);
	if (!(win->wi = mlx_new_window(win->init, 1024, 1024, s)))
		return (0);
	if (!(win = new_picture(win)))
		return (0);
	open_frac(win);
	mlx_key_hook(win->wi, hook_keydown, win);
	mlx_mouse_hook(win->wi, mouse_hook, win);
	mlx_hook(win->wi, 6, 0, hook_mousemove, win);
	mlx_loop(win->init);
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc != 2)
		return (ft_close(NULL));
	if ((make_win(argv[1])) == 0)
		return (ft_close("Error: Some memory problems."));
	return (0);
}
