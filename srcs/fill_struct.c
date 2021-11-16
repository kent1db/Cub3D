/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:33:48 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/18 15:52:47 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_fill_struct(t_map *map)
{
	int	i;

	i = 0;
	map->x_res = 0;
	map->y_res = 0;
	while (i != 3)
	{
		map->f_rgb[i] = -1;
		map->c_rgb[i] = -1;
		i++;
	}
	map->char_c_rgb = NULL;
	map->char_f_rgb = NULL;
	map->path_n = NULL;
	map->path_s = NULL;
	map->path_e = NULL;
	map->path_w = NULL;
	map->path_sprite = NULL;
	map->path_sprite_b = NULL;
	map->map = NULL;
	map->map_check = NULL;
	map->player_pos[0] = 0;
	map->player_pos[1] = 0;
	map->checked = 0;
	map->player_orientation = '0';
}

void	ft_set_resolution(char **tab, t_map *map)
{
	int x;

	x = 0;
	while (tab[x] != NULL)
		x++;
	if (x != 3 || map->x_res != 0 || map->y_res != 0 ||
	ft_check_alpha(tab[1]) || ft_check_alpha(tab[2]))
	{
		ft_free_tab(tab);
		ft_error(5, map);
	}
	map->x_res = ft_atoi(tab[1]);
	map->y_res = ft_atoi(tab[2]);
	if (map->y_res < 100 || map->x_res < 100)
	{
		ft_free_tab(tab);
		ft_error(5, map);
	}
	ft_free_tab(tab);
}

void	ft_set_txt(char **tab, t_map *map, int txt)
{
	int x;

	x = 0;
	while (tab[x] != NULL)
		x++;
	if ((txt == 1 && map->path_n != NULL) || (txt == 2 && map->path_s != NULL)\
	|| (txt == 3 && map->path_w != NULL) || (txt == 4 && map->path_e != NULL)\
	|| (txt == 5 && map->path_sprite != NULL) || x != 2 ||
	(txt == 6 && map->path_sprite_b != NULL))
	{
		ft_free_tab(tab);
		ft_error(5, map);
	}
	free(tab[0]);
	free(tab);
	ft_set_path(txt, map, tab);
}

void	ft_set_color(char **tab, t_map *map, char c)
{
	int x;

	x = 0;
	while (tab[x] != NULL)
		x++;
	if (x != 2)
	{
		ft_free_tab(tab);
		ft_error(5, map);
	}
	if (c == 'F' && map->f_rgb[0] != -1)
	{
		ft_free_tab(tab);
		ft_error(5, map);
	}
	else if (c == 'F')
		ft_get_color_f(tab, map);
	if (c == 'C' && map->c_rgb[0] != -1)
	{
		ft_free_tab(tab);
		ft_error(5, map);
	}
	else if (c == 'C')
		ft_get_color_c(tab, map);
}

int		ft_set_struct(char **tab, t_map *map, int ret)
{
	if (ft_strncmp(tab[0], "R", 2) == 0 && ft_strlen(tab[0]) == 1)
		ft_set_resolution(tab, map);
	else if (ft_strncmp(tab[0], "NO", 3) == 0 && ft_strlen(tab[0]) == 2)
		ft_set_txt(tab, map, 1);
	else if (ft_strncmp(tab[0], "SO", 3) == 0 && ft_strlen(tab[0]) == 2)
		ft_set_txt(tab, map, 2);
	else if (ft_strncmp(tab[0], "WE", 3) == 0 && ft_strlen(tab[0]) == 2)
		ft_set_txt(tab, map, 3);
	else if (ft_strncmp(tab[0], "EA", 3) == 0 && ft_strlen(tab[0]) == 2)
		ft_set_txt(tab, map, 4);
	else if (ft_strncmp(tab[0], "S", 2) == 0 && ft_strlen(tab[0]) == 1)
		ft_set_txt(tab, map, 5);
	else if (ft_strncmp(tab[0], "SB", 3) == 0 && ft_strlen(tab[0]) == 2)
		ft_set_txt(tab, map, 6);
	else if (ft_strncmp(tab[0], "F", 2) == 0 && ft_strlen(tab[0]) == 1)
		ft_set_color(tab, map, 'F');
	else if (ft_strncmp(tab[0], "C", 2) == 0 && ft_strlen(tab[0]) == 1)
		ft_set_color(tab, map, 'C');
	else
		ret = 0;
	return (ret);
}
