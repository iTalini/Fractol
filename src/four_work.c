/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   four_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 14:10:04 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/21 14:10:06 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	four_work(t_win *win)
{
	t_win		map[8];
	pthread_t	t[8];
	int			i;

	i = -1;
	while (++i < 8)
	{
		ft_memcpy((void*)&map[i], (void*)win, sizeof(t_win));
		map[i].y = 128 * i;
		map[i].y_max = 128 * (i + 1);
	}
	i = 0;
	while (++i <= 8)
		pthread_create(&t[i - 1], NULL, cord_vect_four, &map[i - 1]);
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(map->init, map->wi, map->pixel, 0, 0);
	print_config(map);
}

void	*cord_vect_four(void *data)
{
	int		iter;
	double	tmp;
	t_win	*map;

	map = (t_win *)data;
	map->x = -1;
	tmp = map->y - 1;
	while (++map->x < 1024)
	{
		map->y = tmp;
		while (++map->y < map->y_max)
		{
			map->new_i = (map->x - 512) / (map->zoom * 512) + map->move_x;
			map->new_r = (map->y - 512) / (map->zoom * 512) + map->move_y;
			iter = -1;
			while (++iter < map->max_iter
			&& (map->new_r * map->new_r + map->new_i * map->new_i) < 4)
				calc_four(map);
			map_color(iter, map);
			image_set_pixel(map, map->x, map->y, map->color);
		}
	}
	return (map);
}

void	calc_four(t_win *map)
{
	map->old_r = map->new_r;
	map->old_i = map->new_i;
	map->new_r = map->old_r * (map->old_r * map->old_r - 3 *
		map->old_i * map->old_i) + map->option_x;
	map->new_i = map->old_i * (3 * map->old_r *
		map->old_r - map->old_i * map->old_i) + map->option_y;
}
