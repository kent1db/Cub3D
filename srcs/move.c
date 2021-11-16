/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 14:54:26 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/18 15:17:12 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_move_forward(t_ray *ray)
{
	double	afterpos_x;
	double	afterpos_y;

	afterpos_y = ((ray->pos_y) + (ray->dir_y) * (ray->movespeed));
	afterpos_x = ((ray->pos_x) + (ray->dir_x) * (ray->movespeed));
	if (afterpos_x >= 0 && afterpos_y >= 0)
	{
		if (((ray->map_s->map)[(int)afterpos_x][(int)ray->pos_y]) == '0' ||
		((ray->map_s->map)[(int)afterpos_x][(int)ray->pos_y]) == '3')
			ray->pos_x = afterpos_x;
		if (((ray->map_s->map)[(int)ray->pos_x][(int)afterpos_y]) == '0' ||
		((ray->map_s->map)[(int)ray->pos_x][(int)afterpos_y]) == '3')
			ray->pos_y = afterpos_y;
	}
}

void	ft_move_back(t_ray *ray)
{
	double	afterpos_x;
	double	afterpos_y;

	afterpos_y = ((ray->pos_y) - (ray->dir_y) * (ray->movespeed));
	afterpos_x = ((ray->pos_x) - (ray->dir_x) * (ray->movespeed));
	if (afterpos_x >= 0 && afterpos_y >= 0)
	{
		if (((ray->map_s->map)[(int)afterpos_x][(int)ray->pos_y]) == '0' ||
		((ray->map_s->map)[(int)afterpos_x][(int)ray->pos_y]) == '3')
			ray->pos_x = afterpos_x;
		if (((ray->map_s->map)[(int)ray->pos_x][(int)afterpos_y]) == '0' ||
		((ray->map_s->map)[(int)ray->pos_x][(int)afterpos_y]) == '3')
			ray->pos_y = afterpos_y;
	}
}

void	ft_move_right(t_ray *ray)
{
	double	afterpos_x;
	double	afterpos_y;

	afterpos_y = ((ray->pos_y) - (ray->dir_x) * (ray->movespeed));
	afterpos_x = ((ray->pos_x) + (ray->dir_y) * (ray->movespeed));
	if (afterpos_x >= 0 && afterpos_y >= 0)
	{
		if (((ray->map_s->map)[(int)afterpos_x][(int)ray->pos_y]) == '0' ||
		((ray->map_s->map)[(int)afterpos_x][(int)ray->pos_y]) == '3')
			ray->pos_x = afterpos_x;
		if (((ray->map_s->map)[(int)ray->pos_x][(int)afterpos_y]) == '0' ||
		((ray->map_s->map)[(int)ray->pos_x][(int)afterpos_y]) == '3')
			ray->pos_y = afterpos_y;
	}
}

void	ft_move_left(t_ray *ray)
{
	double	afterpos_x;
	double	afterpos_y;

	afterpos_y = ((ray->pos_y) + (ray->dir_x) * (ray->movespeed));
	afterpos_x = ((ray->pos_x) - (ray->dir_y) * (ray->movespeed));
	if (afterpos_x >= 0 && afterpos_y >= 0)
	{
		if (((ray->map_s->map)[(int)afterpos_x][(int)ray->pos_y]) == '0' ||
		((ray->map_s->map)[(int)afterpos_x][(int)ray->pos_y]) == '3')
			ray->pos_x = afterpos_x;
		if (((ray->map_s->map)[(int)ray->pos_x][(int)afterpos_y]) == '0' ||
		((ray->map_s->map)[(int)ray->pos_x][(int)afterpos_y]) == '3')
			ray->pos_y = afterpos_y;
	}
}

void	ft_move_player(t_ray *ray)
{
	if ((ray->player[0] == 1 && ray->player[3] == 1) ||
	(ray->player[0] == 1 && ray->player[1] == 1) ||
	(ray->player[2] == 1 && ray->player[3] == 1) ||
	(ray->player[2] == 1 && ray->player[1] == 1))
		ray->movespeed /= 2;
	if (ray->player[0] == 1)
		ft_move_forward(ray);
	if (ray->player[2] == 1)
		ft_move_back(ray);
	if (ray->player[3] == 1)
		ft_move_right(ray);
	if (ray->player[1] == 1)
		ft_move_left(ray);
}
