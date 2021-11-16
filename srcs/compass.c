/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compass.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:26:18 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/17 15:30:22 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init_compass(t_ray *r, t_data *d)
{
	d->img_o[0] = mlx_xpm_file_to_image(r->win_s->mlx, "./txt/N.xpm",
	&d->width_o[0], &d->height_o[0]);
	d->addr_o[0] = (int*)mlx_get_data_addr(d->img_o[0], &d->bits_per_pixel_o[0],
	&d->line_length_o[0], &d->endian_o[0]);
	d->img_o[1] = mlx_xpm_file_to_image(r->win_s->mlx, "./txt/S.xpm",
	&d->width_o[1], &d->height_o[1]);
	d->addr_o[1] = (int*)mlx_get_data_addr(d->img_o[1], &d->bits_per_pixel_o[1],
	&d->line_length_o[1], &d->endian_o[1]);
	d->img_o[2] = mlx_xpm_file_to_image(r->win_s->mlx, "./txt/E.xpm",
	&d->width_o[2], &d->height_o[2]);
	d->addr_o[2] = (int*)mlx_get_data_addr(d->img_o[2], &d->bits_per_pixel_o[2],
	&d->line_length_o[2], &d->endian_o[2]);
	d->img_o[3] = mlx_xpm_file_to_image(r->win_s->mlx, "./txt/W.xpm",
	&d->width_o[3], &d->height_o[3]);
	d->addr_o[3] = (int*)mlx_get_data_addr(d->img_o[3], &d->bits_per_pixel_o[3],
	&d->line_length_o[3], &d->endian_o[3]);
}

void	ft_check_orientation(t_ray *ray, int *ret, int *x, int *y)
{
	if (ray->side == 0)
	{
		if (ray->dir_ray_x < 0.0)
			*ret = 0;
		else if (ray->dir_ray_x > 0.0)
			*ret = 1;
		*x = ray->map_s->x_res - 64;
	}
	else if (ray->side == 1)
	{
		if (ray->dir_ray_y > 0.0)
		{
			*ret = 2;
			*x = ray->map_s->x_res - 122;
		}
		else if (ray->dir_ray_y < 0.0)
		{
			*ret = 3;
			*x = ray->map_s->x_res - 143;
		}
	}
	*y = 0;
}
