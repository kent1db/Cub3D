/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycasting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:34:04 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/17 16:13:57 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init_struct(t_window *w, t_map *m, t_ray *r, t_data *d)
{
	int		i;
	t_txt	*t;

	if (!(t = malloc(sizeof(t_txt))))
		return ;
	i = -1;
	r->map_s = m;
	r->win_s = w;
	r->data_s = d;
	w->text = t;
	r->txt_s = t;
	r->txt_s->wall_x = 0;
	while (++i != 4)
		r->player[i] = 0;
	i = -1;
	while (++i != 2)
		r->camera[i] = 0;
	r->maj = 0;
	r->screen = 0;
}

void	ft_orientation_dir(t_ray *ray, t_map *map)
{
	if (map->player_orientation == 'N')
	{
		ray->dir_x = -1;
		ray->dir_y = 0;
	}
	else if (map->player_orientation == 'S')
	{
		ray->dir_x = 1;
		ray->dir_y = 0;
	}
	else if (map->player_orientation == 'E')
	{
		ray->dir_x = 0;
		ray->dir_y = 1;
	}
	else if (map->player_orientation == 'W')
	{
		ray->dir_x = 0;
		ray->dir_y = -1;
	}
}

void	ft_init_raycasting(t_ray *ray, t_map *map)
{
	ft_orientation_dir(ray, map);
	ray->pos_x = (double)map->player_pos[1] + 0.5;
	ray->pos_y = (double)map->player_pos[0] + 0.5;
	if (map->player_orientation == 'N')
	{
		ray->plane_x = 0;
		ray->plane_y = 0.66;
	}
	if (map->player_orientation == 'S')
	{
		ray->plane_x = 0;
		ray->plane_y = -0.66;
	}
	if (map->player_orientation == 'E')
	{
		ray->plane_x = 0.66;
		ray->plane_y = 0;
	}
	if (map->player_orientation == 'W')
	{
		ray->plane_x = -0.66;
		ray->plane_y = 0;
	}
	ray->old_dir_x = 0;
	ray->old_plane_x = 0;
}

void	ft_init_variables(t_ray *ray, t_map *m, int x)
{
	ray->x_coordinate = 2 * x / (double)m->x_res - 1;
	ray->dir_ray_x = (ray->dir_x) + (ray->plane_x) * (ray->x_coordinate);
	ray->dir_ray_y = (ray->dir_y) + (ray->plane_y) * (ray->x_coordinate);
	ray->map_x = (int)(ray->pos_x);
	ray->map_y = (int)(ray->pos_y);
	if (ray->dir_ray_y == 0)
	{
		ray->dist_delta_x = 0;
		ray->dist_delta_y = 1;
	}
	if (ray->dir_ray_x == 0)
	{
		ray->dist_delta_y = 0;
		ray->dist_delta_x = 1;
	}
	else
	{
		ray->dist_delta_y = fabs(1 / ray->dir_ray_y);
		ray->dist_delta_x = fabs(1 / ray->dir_ray_x);
	}
	ray->rotspeed = 0.03;
	ft_init_step_side(ray);
}

void	ft_init_step_side(t_ray *ray)
{
	if (ray->dir_ray_x < 0)
	{
		ray->step_x = -1;
		ray->dist_side_x = (ray->pos_x - ray->map_x) * ray->dist_delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->dist_side_x = (ray->map_x + 1.0 - ray->pos_x) * ray->dist_delta_x;
	}
	if (ray->dir_ray_y < 0)
	{
		ray->step_y = -1;
		ray->dist_side_y = (ray->pos_y - ray->map_y) * ray->dist_delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->dist_side_y = (ray->map_y + 1.0 - ray->pos_y) * ray->dist_delta_y;
	}
}
