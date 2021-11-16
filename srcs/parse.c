/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:10:40 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/18 14:49:35 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_get_size_map(t_map *map)
{
	int a;
	int b;
	int count;

	a = 0;
	count = 0;
	while ((map->map_check)[a] != NULL)
	{
		b = 0;
		while ((map->map_check)[a][b] != '\0')
			b++;
		if (b > count)
			count = b;
		a++;
	}
	map->width = count;
	map->height = a;
}

void	ft_parse_map(char *line, t_map *map)
{
	if (line[0] == '\0' && map->map != NULL)
		ft_error(100, map);
	if (map->checked == 0)
	{
		if (!(ft_check_struct(map)))
			ft_error(5, map);
		else
			map->checked = 1;
	}
	if (line && line[0] != '\0')
	{
		map->map = ft_strsjoin(line, map->map);
		if (map->map == NULL)
			ft_error(7, map);
	}
}

void	ft_flood_fill(int x, int y, t_map *map)
{
	if (y >= ft_strslen(map->map_check) || y < 0 ||
	x >= (int)ft_strlen((map->map_check)[y]) || x < 0 ||
	(map->map_check)[y][x] == ' ')
		ft_error(100, map);
	if ((map->map_check)[y][x] == '0' || (map->map_check)[y][x] == '2' ||
		(map->map_check)[y][x] == '3' || (map->map_check)[y][x] == '4')
	{
		(map->map_check)[y][x] = 'V';
		ft_flood_fill(x, y - 1, map);
		ft_flood_fill(x, y + 1, map);
		ft_flood_fill(x - 1, y, map);
		ft_flood_fill(x + 1, y, map);
	}
}

void	ft_initialize_struct(char *line, t_map *map, int *count)
{
	char	**tab;
	int		i;

	i = -1;
	if (line[0] != '\0')
	{
		tab = ft_split(line, ' ');
		ft_set_struct(tab, map, 1);
		(*count)++;
	}
}

void	ft_parse(int fd, t_map *map)
{
	char	*line;
	int		ret;
	int		count;

	ret = 1;
	count = 0;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (line)
		{
			if (ft_check_for_split(line) && count < 9)
				ft_initialize_struct(line, map, &count);
			else
				ft_parse_map(line, map);
		}
		free(line);
	}
	if (count != 9)
		ft_error(5, map);
	ft_check_map(map);
	ft_get_size_map(map);
}
