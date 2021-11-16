/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:51:15 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/17 14:33:55 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_header_bmp(char *header, t_ray *ray)
{
	t_bmp screen;

	screen.image_s = (((ray->map_s->x_res * 32 + 31) / 32) * 4) *
	ray->map_s->y_res;
	screen.file_s = screen.image_s + 54;
	screen.header_s = 54;
	screen.byte_s = 40;
	screen.b_planes = 1;
	screen.bytes_number = 32;
	ft_memmove(header, "BM", 2);
	ft_memmove(header + 2, &screen.file_s, 4);
	ft_memmove(header + 10, &screen.header_s, 4);
	ft_memmove(header + 14, &screen.byte_s, 4);
	ft_memmove(header + 18, &ray->map_s->x_res, 4);
	ft_memmove(header + 22, &ray->map_s->y_res, 4);
	ft_memmove(header + 26, &screen.b_planes, 4);
	ft_memmove(header + 28, &screen.bytes_number, 4);
	ft_memmove(header + 34, &screen.image_s, 4);
}

void	ft_screen(t_ray *ray)
{
	int		fd;
	char	header[54];
	int		i;

	ft_game(ray);
	i = ray->map_s->y_res;
	fd = open("cub3D.bmp", O_WRONLY | O_TRUNC | O_CREAT, 0777);
	bzero(header, 54);
	ft_header_bmp(header, ray);
	write(fd, header, 54);
	while (i != 0)
		write(fd, (int *)ray->data_s->addr + (i-- * ray->map_s->x_res),
		ray->map_s->x_res * 4);
	close(fd);
	if (ray->map_s)
		ft_free_struct(ray->map_s);
	if (ray->txt_s)
		free(ray->txt_s);
	ft_close(0);
}
