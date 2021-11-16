/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:45:18 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/18 14:52:04 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_check_alpha(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_tab(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		if (ft_isalpha(str[i]))
			return (1);
		i++;
	}
	if (count != 2)
		return (1);
	return (0);
}

int		ft_check_for_split(char *line)
{
	int i;

	i = 0;
	if (line[0] == '\0')
		return (1);
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == 'R' || line[i] == 'S' || line[i] == 'F' ||
		line[i] == 'C' || (line[i] == 'N' && line[i + 1] == 'O') ||
		(line[i] == 'S' && line[i + 1] == 'O') ||
		(line[i] == 'W' && line[i + 1] == 'E') ||
		(line[i] == 'E' && line[i + 1] == 'A') ||
		(line[i] == 'S' && line[i + 1] == 'B'))
			return (1);
		if (line[i])
			i++;
	}
	return (0);
}

void	ft_check_map(t_map *map)
{
	t_check	c;

	c.i = -1;
	while ((map->map)[++(c.i)] != NULL)
	{
		c.a = -1;
		while ((map->map)[c.i][++(c.a)] != '\0')
		{
			if (ft_str_search("NSEW", (map->map)[c.i][c.a]))
			{
				if (map->player_orientation != '0')
					ft_error(5, map);
				map->player_orientation = (map->map)[c.i][c.a];
				map->player_pos[0] = c.a;
				map->player_pos[1] = c.i;
				(map->map)[c.i][c.a] = '0';
			}
			if (!(ft_str_search("01234NSEW ", (map->map)[c.i][c.a])))
				ft_error(5, map);
		}
	}
	if (map->player_orientation == '0')
		ft_error(5, map);
	map->map_check = ft_strsdup(map->map);
	ft_flood_fill(map->player_pos[0], map->player_pos[1], map);
}

int		ft_check_struct(t_map *map)
{
	if (map->x_res == 0 || map->y_res == 0 || map->f_rgb[0] < 0 ||
	map->f_rgb[1] < 0 || map->f_rgb[2] < 0 || map->c_rgb[0] < 0 ||
	map->c_rgb[1] < 0 || map->c_rgb[2] < 0 || map->char_c_rgb == NULL ||
	map->char_f_rgb == NULL || map->path_n == NULL || map->path_s == NULL ||
	map->path_e == NULL || map->path_w == NULL || map->path_sprite == NULL ||
	map->path_sprite_b == NULL)
		return (0);
	if (ft_check_open_e(map) || ft_check_open_n(map) || ft_check_open_s(map) ||
		ft_check_open_w(map) || ft_check_open_sprite(map) || ft_check_open(map))
		return (0);
	return (1);
}
