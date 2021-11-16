/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 10:23:43 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/18 15:52:52 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_set_path(int txt, t_map *map, char **tab)
{
	if (txt == 1)
		map->path_n = tab[1];
	else if (txt == 2)
		map->path_s = tab[1];
	else if (txt == 3)
		map->path_w = tab[1];
	else if (txt == 4)
		map->path_e = tab[1];
	else if (txt == 5)
		map->path_sprite = tab[1];
	else if (txt == 6)
		map->path_sprite_b = tab[1];
}

int		ft_check_open(t_map *map)
{
	int len;
	int fd;

	len = ft_strlen(map->path_sprite_b) - 4;
	if (ft_strncmp(&map->path_sprite_b[len], ".xpm", 5) != 0)
		return (1);
	if ((fd = open(map->path_sprite_b, O_RDONLY, O_DIRECTORY) < 0))
		return (1);
	else
		close(fd);
	return (0);
}

void	ft_init_direction_text(t_window *w, t_map *m)
{
	w->text->img_n = mlx_xpm_file_to_image(w->mlx, m->path_n, &(w->text->width),
	&(w->text->height));
	w->text->addr_n = (int*)mlx_get_data_addr(w->text->img_n,
	&(w->text->bits_per_pixel),
	&(w->text->line_length), &(w->text->endian));
	w->text->img_s = mlx_xpm_file_to_image(w->mlx, m->path_s, &(w->text->width),
	&(w->text->height));
	w->text->addr_s = (int*)mlx_get_data_addr(w->text->img_s,
	&(w->text->bits_per_pixel),
	&(w->text->line_length), &(w->text->endian));
	w->text->img_e = mlx_xpm_file_to_image(w->mlx, m->path_e,
	&(w->text->width), &(w->text->height));
	w->text->addr_e = (int*)mlx_get_data_addr(w->text->img_e,
	&(w->text->bits_per_pixel),
	&(w->text->line_length), &(w->text->endian));
	w->text->img_w = mlx_xpm_file_to_image(w->mlx, m->path_w,
	&(w->text->width), &(w->text->height));
	w->text->addr_w = (int*)mlx_get_data_addr(w->text->img_w,
	&(w->text->bits_per_pixel),
	&(w->text->line_length), &(w->text->endian));
}

void	ft_init_sprite_texture(t_window *w, t_map *m, t_data *d, t_sprt *sprt)
{
	sprt->img = mlx_xpm_file_to_image(w->mlx, m->path_sprite, &(sprt->width),
	&(sprt->height));
	sprt->addr = (int*)mlx_get_data_addr(sprt->img, &sprt->bits_per_pixel,
	&sprt->line_length, &sprt->endian);
	sprt->img_b = mlx_xpm_file_to_image(w->mlx, m->path_sprite_b,
	&(sprt->width_b), &(sprt->height_b));
	sprt->addr_b = (int*)mlx_get_data_addr(sprt->img_b, &sprt->bits_per_pixel_b,
	&sprt->line_length_b, &sprt->endian_b);
	d->img_b = mlx_xpm_file_to_image(w->mlx, "./txt/heart_small_clean.xpm",
	&d->width_b, &d->height_b);
	d->addr_b = (int*)mlx_get_data_addr(d->img_b, &d->bits_per_pixel_b,
	&d->line_length_b, &d->endian_b);
}

void	ft_init_mlx(t_window *w, t_map *m, t_data *d, t_sprt *sprt)
{
	mlx_get_screen_size(w->mlx, &w->size_x, &w->size_y);
	ft_resolution(m, w);
	w->win = mlx_new_window(w->mlx, m->x_res, m->y_res, "CUB3D");
	d->img = mlx_new_image(w->mlx, m->x_res, m->y_res);
	d->addr = (int*)mlx_get_data_addr(d->img, &d->bits_per_pixel,
	&d->line_length, &d->endian);
	ft_init_direction_text(w, m);
	ft_init_sprite_texture(w, m, d, sprt);
}
