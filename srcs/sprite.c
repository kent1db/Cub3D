/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 11:18:08 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/18 15:14:26 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_print_s(t_sprt *s, t_map *map, t_data *data, int *addr)
{
	int d;
	int y;
	int stripe;

	stripe = s->drawstart_x - 1;
	while (++stripe < s->drawend_x)
	{
		s->tex_x = (int)(256 * (stripe - (-s->sprite_width / 2 +
		s->sprite_screen_x)) * s->width / s->sprite_width) / 256;
		y = s->drawstart_y - 1;
		if (s->transform_y > 0 && stripe > 0 &&
			stripe < map->x_res && s->transform_y < map->z_buf[stripe])
			while (++y < s->drawend_y)
			{
				d = (y - s->v_move_screen) * 256 - map->y_res * 128 +
				s->sprite_height * 128;
				s->tex_y = ((d * s->height) / s->sprite_height) / 256;
				if (addr[s->width * s->tex_y + s->tex_x] != 0x980088)
					data->addr[y * map->x_res + stripe] = addr[s->width *
					s->tex_y + s->tex_x];
			}
	}
}

void	ft_init_sprite_variables(t_sprt *s, t_ray *r, t_map *m)
{
	s->inv_det = 1.0 / (r->plane_x * r->dir_y - r->dir_x * r->plane_y);
	s->transform_x = s->inv_det * (r->dir_y * s->sprite_x - r->dir_x *
	s->sprite_y);
	s->transform_y = s->inv_det * (-r->plane_y * s->sprite_x + r->plane_x *
	s->sprite_y);
	s->sprite_screen_x = (int)((m->x_res / 2) * (1 + s->transform_x /
	s->transform_y));
	s->v_move_screen = (int)(s->v_move / s->transform_y);
	s->sprite_height = abs((int)((m->y_res / s->transform_y) / s->v_div));
	s->drawstart_y = -s->sprite_height / 2 + m->y_res / 2 + s->v_move_screen;
	if (s->drawstart_y < 0)
		s->drawstart_y = 0;
	s->drawend_y = s->sprite_height / 2 + m->y_res / 2 + s->v_move_screen;
	if (s->drawend_y >= m->y_res)
		s->drawend_y = m->y_res - 1;
	s->sprite_width = abs((int)((m->y_res / s->transform_y) / s->u_div));
	s->drawstart_x = -s->sprite_width / 2 + s->sprite_screen_x;
	if (s->drawstart_x < 0)
		s->drawstart_x = 0;
	s->drawend_x = s->sprite_width / 2 + s->sprite_screen_x;
	if (s->drawend_x >= m->x_res)
		s->drawend_x = m->x_res - 1;
}

void	ft_spriting(t_sprt *s, t_ray *r, t_map *m, t_data *data)
{
	int		i;
	int		*addr;

	i = -1;
	while (++i < s->number_sprite)
	{
		if (s->sprite[i].type == '2')
			addr = s->addr;
		else
			addr = s->addr_b;
		s->sprite_x = (s->sprite[i].x) - r->pos_x + 0.5;
		s->sprite_y = (s->sprite[i].y) - r->pos_y + 0.5;
		ft_init_sprite_variables(s, r, m);
		ft_print_s(s, m, data, addr);
	}
}
