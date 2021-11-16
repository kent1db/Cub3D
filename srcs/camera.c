/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:31:15 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/17 14:34:40 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_cam_right(t_ray *ray)
{
	ray->old_dir_x = ray->dir_x;
	ray->old_plane_x = ray->plane_x;
	ray->dir_x = ray->dir_x * cos(-ray->rotspeed) - ray->dir_y *
	sin(-ray->rotspeed);
	ray->dir_y = ray->old_dir_x * sin(-ray->rotspeed) + ray->dir_y *
	cos(-ray->rotspeed);
	ray->plane_x = ray->plane_x * cos(-ray->rotspeed) - ray->plane_y *
	sin(-ray->rotspeed);
	ray->plane_y = ray->old_plane_x * sin(-ray->rotspeed) + ray->plane_y *
	cos(-ray->rotspeed);
}

void	ft_cam_left(t_ray *ray)
{
	ray->old_dir_x = ray->dir_x;
	ray->old_plane_x = ray->plane_x;
	ray->dir_x = ray->dir_x * cos(ray->rotspeed) - ray->dir_y *
	sin(ray->rotspeed);
	ray->dir_y = ray->old_dir_x * sin(ray->rotspeed) + ray->dir_y *
	cos(ray->rotspeed);
	ray->plane_x = ray->plane_x * cos(ray->rotspeed) - ray->plane_y *
	sin(ray->rotspeed);
	ray->plane_y = ray->old_plane_x * sin(ray->rotspeed) + ray->plane_y *
	cos(ray->rotspeed);
}

void	ft_move_camera(t_ray *ray)
{
	if (ray->camera[1] == 1)
		ft_cam_right(ray);
	if (ray->camera[0] == 1)
		ft_cam_left(ray);
}
