/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_txt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:22:35 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/18 15:18:31 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_check_open_e(t_map *map)
{
	int len;
	int fd;

	len = ft_strlen(map->path_e) - 4;
	if (ft_strncmp(&map->path_e[len], ".xpm", 5) != 0)
		return (1);
	if ((fd = open(map->path_e, O_RDONLY, O_DIRECTORY) < 0))
		return (1);
	else
		close(fd);
	return (0);
}

int		ft_check_open_n(t_map *map)
{
	int len;
	int fd;

	len = ft_strlen(map->path_n) - 4;
	if (ft_strncmp(&map->path_n[len], ".xpm", 5) != 0)
		return (1);
	if ((fd = open(map->path_n, O_RDONLY, O_DIRECTORY) < 0))
		return (1);
	else
		close(fd);
	return (0);
}

int		ft_check_open_s(t_map *map)
{
	int len;
	int fd;

	len = ft_strlen(map->path_s) - 4;
	if (ft_strncmp(&map->path_s[len], ".xpm", 5) != 0)
		return (1);
	if ((fd = open(map->path_s, O_RDONLY, O_DIRECTORY) < 0))
		return (1);
	else
		close(fd);
	return (0);
}

int		ft_check_open_w(t_map *map)
{
	int	len;
	int	fd;

	len = ft_strlen(map->path_w) - 4;
	if (ft_strncmp(&map->path_w[len], ".xpm", 5) != 0)
		return (1);
	if ((fd = open(map->path_w, O_RDONLY, O_DIRECTORY) < 0))
		return (1);
	else
		close(fd);
	return (0);
}

int		ft_check_open_sprite(t_map *map)
{
	int len;
	int fd;

	len = ft_strlen(map->path_sprite) - 4;
	if (ft_strncmp(&map->path_sprite[len], ".xpm", 5) != 0)
		return (1);
	if ((fd = open(map->path_sprite, O_RDONLY, O_DIRECTORY) < 0))
		return (1);
	else
		close(fd);
	return (0);
}
