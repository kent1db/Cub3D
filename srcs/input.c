/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 10:51:20 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/17 16:14:37 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_input_on(int keycode, t_ray *ray)
{
	if (keycode == 53)
		ft_close(0);
	if (keycode == 13)
		ray->player[0] = 1;
	if (keycode == 0)
		ray->player[1] = 1;
	if (keycode == 1)
		ray->player[2] = 1;
	if (keycode == 2)
		ray->player[3] = 1;
	if (keycode == 123)
		ray->camera[0] = 1;
	if (keycode == 124)
		ray->camera[1] = 1;
	if (keycode == 257)
		ray->maj = 1;
	return (0);
}

int		ft_input_off(int keycode, t_ray *ray)
{
	if (keycode == 13)
		ray->player[0] = 0;
	if (keycode == 0)
		ray->player[1] = 0;
	if (keycode == 1)
		ray->player[2] = 0;
	if (keycode == 2)
		ray->player[3] = 0;
	if (keycode == 123)
		ray->camera[0] = 0;
	if (keycode == 124)
		ray->camera[1] = 0;
	if (keycode == 257)
		ray->maj = 0;
	return (0);
}

int		ft_key(t_ray *ray)
{
	int i;

	i = -1;
	while (++i != 4)
	{
		if (ray->player[i] == 1)
			ft_move_player(ray);
	}
	i = -1;
	while (++i != 2)
	{
		if (ray->camera[i] == 1)
			ft_move_camera(ray);
	}
	ray->movespeed = 0.05;
	if (ray->maj == 1)
		ray->movespeed *= 2;
	return (0);
}

int		ft_game(t_ray *ray)
{
	int ret;
	int x;
	int y;

	ft_key(ray);
	ft_check_orientation(ray, &ret, &x, &y);
	mlx_put_image_to_window(ray->win_s->mlx, ray->win_s->win,
	ray->data_s->img, 0, 0);
	mlx_put_image_to_window(ray->win_s->mlx, ray->win_s->win,
	ray->data_s->img_b, 0, 0);
	mlx_put_image_to_window(ray->win_s->mlx, ray->win_s->win,
	ray->data_s->img_o[ret], x, y);
	mlx_destroy_image(ray->win_s->mlx, ray->data_s->img);
	ray->data_s->img = mlx_new_image(ray->win_s->mlx, ray->map_s->x_res,
	ray->map_s->y_res);
	ray->data_s->addr = (int*)mlx_get_data_addr(ray->data_s->img,
	&ray->data_s->bits_per_pixel,
	&ray->data_s->line_length, &ray->data_s->endian);
	ft_raycasting_loop(ray, ray->map_s, ray->data_s, ray->sprt_s);
	free(ray->sprt_s->sprite);
	return (0);
}
