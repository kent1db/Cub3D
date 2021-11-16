/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:05:42 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/18 15:05:07 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init_sprite_struct(t_sprt *sprt, t_ray *ray, t_map *map)
{
	int x;
	int y;

	x = -1;
	ray->sprt_s = sprt;
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
		{
			if (map->map[x][y] == '2' || map->map[x][y] == '4')
			{
				(sprt->number_sprite)++;
			}
		}
	}
	sprt->u_div = 1;
	sprt->v_div = 1;
	sprt->v_move = 0.0;
}

void	ft_sort_sprite(t_coord *tab, int number)
{
	int		i;
	t_coord	temp;

	i = 0;
	while (i < number - 1)
	{
		if ((tab)[i].distance < (tab)[i + 1].distance)
		{
			temp = (tab)[i];
			(tab)[i] = (tab)[i + 1];
			(tab)[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	i = 0;
}

t_coord	*ft_fill_struct_sprite(t_sprt *sprt, t_map *map, t_ray *ray)
{
	int		x;
	int		y;
	int		i;
	t_coord	*sprite;

	x = -1;
	i = -1;
	if (!(sprite = malloc(sizeof(t_coord) * sprt->number_sprite)))
		return (NULL);
	while (map->map[++x])
	{
		y = -1;
		while (map->map[x][++y])
			if (map->map[x][y] == '2' || map->map[x][y] == '4')
			{
				sprite[++i].x = x;
				sprite[i].y = y;
				sprite[i].type = map->map[x][y];
				sprite[i].distance = ft_power((ray->pos_x - x), 2) +
				ft_power((ray->pos_y - y), 2);
			}
	}
	return (sprite);
}
