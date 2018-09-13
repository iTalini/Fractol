/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 11:19:29 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/14 11:19:31 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include "../libft/libft.h"
# include <mlx.h>
# include <stdio.h>
# include <pthread.h>

typedef struct		s_win
{
	void			*wi;
	void			*init;
	void			*pixel;
	char			*ptr;
	double			pr;
	double			x;
	double			y;
	double			x1;
	double			y1;
	double			x2;
	double			y2;
	double			pi;
	double			ci;
	double			cr;
	double			color_value;
	double			change_julia;
	double			new_r;
	double			new_i;
	double			old_r;
	double			old_i;
	double			zoom;
	double			move_x;
	double			move_y;
	double			max_iter;
	double			option_y;
	double			option_x;
	double			y_max;
	int				w;
	int				color;
	int				stride;
	int				end;
	int				num;
}					t_win;

void				julia_work(t_win *win);
void				mandel_work(t_win *win);
void				spider_work(t_win *win);
void				mandelbar_work(t_win *win);
void				bio_work(t_win *win);
void				four_work(t_win *win);
void				burningship_work(t_win *win);
void				rubber_work(t_win *win);
void				*cord_vect_burningship(void *data);
void				*cord_vect_rubber(void *data);
void				*cord_vect_bio(void *data);
void				*cord_vect_four(void *data);
void				*cord_vect_spider(void *data);
void				*cord_vect_julia(void *data);
void				*cord_vect_mandelbar(void *data);
void				*cord_vect_mandel(void *data);
void				calc_spider(t_win *map);
void				calc_rubber(t_win *map);
void				calc_mandelbar(t_win *map);
void				calc_mandel(t_win *map);
void				calc_julia(t_win *map);
void				calc_four(t_win *map);
void				calc_burningship(t_win *map);
void				calc_bio(t_win *map);
void				with_start(t_win *win);
int					mouse_hook(int k, int x, int y, t_win *win);
int					hook_mousemove(int x, int y, t_win *win);
void				dop_pict(t_win *win);
void				shift(t_win *win, int key);
void				col_of_iter(t_win *win, int key);
void				plus_or_minus(t_win *win, int key);
void				change_color(t_win *win);
void				image_set_pixel(t_win *win, int x, int y, int c);
t_win				*new_picture(t_win *win);
void				print_config(t_win *map);
void				change_fractal(t_win *win, int key);
void				open_frac(t_win *win);
int					ft_close(char *s);
int					hook_keydown(int key, t_win *win);
int					make_win(char *s);
void				map_color(int iteration, t_win *map);
#endif
