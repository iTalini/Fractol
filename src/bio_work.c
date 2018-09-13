/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bio_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurilen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 18:19:46 by akurilen          #+#    #+#             */
/*   Updated: 2018/07/21 18:19:47 by akurilen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	bio_work(t_win *win)
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
		pthread_create(&t[i - 1], NULL, cord_vect_bio, &map[i - 1]);
	while (i--)
		pthread_join(t[i], NULL);
	mlx_put_image_to_window(map->init, map->wi, map->pixel, 0, 0);
	print_config(map);
}

void	*cord_vect_bio(void *data)
{
	int		iter;
	double	tmp;
	t_win	*map;

	map = (t_win *)data;
	map->x = -1;
	map->option_x = 1;
	map->option_y = 0.5;
	tmp = map->y - 1;
	while (++map->x < 1024)
	{
		map->y = tmp;
		while (++map->y < map->y_max)
		{
			map->new_i = 1.5 * (map->x - 512) / (map->zoom * 512) + map->move_x;
			map->new_r = (map->y - 512) / (map->zoom * 512) + map->move_y;
			iter = -1;
			while (++iter < map->max_iter &&
				(map->new_r * map->new_r + map->new_i * map->new_i) < 4)
				calc_bio(map);
			map_color(iter, map);
			image_set_pixel(map, map->x, map->y, map->color);
		}
	}
	return (map);
}

void	calc_bio(t_win *map)
{
	map->old_r = map->new_r;
	map->old_i = map->new_i;
	map->new_r = map->old_r * map->old_r * map->old_r *
	map->old_r + map->old_i
	* map->old_i * map->old_i * map->old_i - 6 *
	map->old_i * map->old_i * map->old_r * map->old_r + map->option_x;
	map->new_i = 4 * map->old_i * map->old_i * map->old_i
	* map->old_r - 4 * map->old_i * map->old_r * map->old_r
	* map->old_r + map->option_y;
}
