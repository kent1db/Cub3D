/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:51:07 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/18 10:40:29 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_dda_algo(t_ray *ray, t_map *map)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->dist_side_x < ray->dist_side_y)
		{
			ray->dist_side_x += ray->dist_delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->dist_side_y += ray->dist_delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if ((map->map)[ray->map_x][ray->map_y] == '1' ||
		(map->map)[ray->map_x][ray->map_y] == '3')
			ray->hit = 1;
	}
}

void	ft_calculate_walldist(t_ray *ray, t_map *map)
{
	if (ray->side == 0)
	{
		ray->dist_to_wall = (ray->map_x - ray->pos_x + (1 - ray->step_x) / 2) /
		ray->dir_ray_x;
	}
	else
		ray->dist_to_wall = (ray->map_y - ray->pos_y + (1 - ray->step_y) / 2) /
		ray->dir_ray_y;
	if (ray->dist_to_wall == 0)
		ray->line_height = (int)map->y_res;
	else
		ray->line_height = (int)((map->y_res) / (ray->dist_to_wall));
}

void	ft_calculate_draw_pixels(t_ray *ray, t_map *map)
{
	ray->draw_start = -(ray->line_height) / 2 + (map->y_res) / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height) / 2 + (map->y_res) / 2;
	if (ray->draw_end >= map->y_res)
		ray->draw_end = map->y_res - 1;
}

void	ft_vertline(int x, t_ray *ray, t_data *data)
{
	int i;
	int y;

	y = -1;
	i = ray->draw_start;
	while (++y != i)
	{
		data->addr[y * ray->map_s->x_res + x] = ray->map_s->c_rgb[0] * 16 * 16 *
		16 * 16 + ray->map_s->c_rgb[1] * 16 * 16 + ray->map_s->c_rgb[2];
	}
	while (i != ray->draw_end && i < ray->map_s->y_res)
	{
		ray->txt_s->tex_y = (int)ray->txt_s->tex_pos & (ray->txt_s->height - 1);
		ray->txt_s->tex_pos += ray->txt_s->step;
		if (i * ray->map_s->x_res + x < (ray->map_s->x_res * ray->map_s->y_res))
			data->addr[i * ray->map_s->x_res + x] = ray->txt_s->addr_p
			[ray->txt_s->height * ray->txt_s->tex_y + ray->txt_s->tex_x];
		ft_shade_color(&data->addr[i * ray->map_s->x_res + x], ray);
		i++;
	}
	while (i != ray->map_s->y_res)
	{
		data->addr[i++ * ray->map_s->x_res + x] = ray->map_s->f_rgb[0] * 16 *
		16 * 16 * 16 + ray->map_s->f_rgb[1] * 16 * 16 + ray->map_s->f_rgb[2];
	}
}

void	ft_raycasting_loop(t_ray *r, t_map *m, t_data *d, t_sprt *s)
{
	int		x;
	int		i;
	double	z_buffer[m->x_res];

	x = -1;
	i = -1;
	while (++x < m->x_res)
	{
		ft_init_variables(r, m, x);
		ft_dda_algo(r, m);
		ft_calculate_walldist(r, m);
		ft_calculate_draw_pixels(r, m);
		ft_texturing(r, m);
		ft_get_orientation_texture(r);
		ft_vertline(x, r, d);
		z_buffer[x] = r->dist_to_wall;
	}
	s->sprite = ft_fill_struct_sprite(s, m, r);
	ft_sort_sprite(s->sprite, s->number_sprite);
	m->z_buf = z_buffer;
	ft_spriting(s, r, m, d);
}
