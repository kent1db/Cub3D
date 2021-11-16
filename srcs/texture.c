/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:33:07 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/17 16:19:40 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		ft_get_orientation_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dir_ray_x < 0.0)
			ray->txt_s->addr_p = ray->txt_s->addr_n;
		else if (ray->dir_ray_x > 0.0)
			ray->txt_s->addr_p = ray->txt_s->addr_s;
	}
	else if (ray->side == 1)
	{
		if (ray->dir_ray_y > 0.0)
			ray->txt_s->addr_p = ray->txt_s->addr_e;
		else if (ray->dir_ray_y < 0.0)
			ray->txt_s->addr_p = ray->txt_s->addr_w;
	}
}

void		ft_texturing(t_ray *ray, t_map *map)
{
	int	y;

	y = ray->draw_start - 1;
	if (ray->side == 0)
		ray->txt_s->wall_x = ray->pos_y + ray->dist_to_wall * ray->dir_ray_y;
	else
		ray->txt_s->wall_x = ray->pos_x + ray->dist_to_wall * ray->dir_ray_x;
	ray->txt_s->wall_x -= floor(ray->txt_s->wall_x);
	ray->txt_s->tex_x = (int)(ray->txt_s->wall_x * (double)ray->txt_s->width);
	if (ray->side == 0 && ray->dir_ray_x > 0)
		ray->txt_s->tex_x = ray->txt_s->width - ray->txt_s->tex_x - 1;
	if (ray->side == 1 && ray->dir_ray_y < 0)
		ray->txt_s->tex_x = ray->txt_s->width - ray->txt_s->tex_x - 1;
	ray->txt_s->step = 1.0 * ray->txt_s->height / ray->line_height;
	ray->txt_s->tex_pos = (ray->draw_start - map->y_res / 2 +
	ray->line_height / 2) * ray->txt_s->step;
	(void)map;
}
