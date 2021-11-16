/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:08:10 by qurobert          #+#    #+#             */
/*   Updated: 2021/01/29 10:23:11 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_char_to_int(t_map *map, int bool)
{
	if (bool == 1)
	{
		map->f_rgb[0] = ft_atoi(map->char_f_rgb[0]);
		map->f_rgb[1] = ft_atoi(map->char_f_rgb[1]);
		map->f_rgb[2] = ft_atoi(map->char_f_rgb[2]);
	}
	if (bool == 2)
	{
		map->c_rgb[0] = ft_atoi(map->char_c_rgb[0]);
		map->c_rgb[1] = ft_atoi(map->char_c_rgb[1]);
		map->c_rgb[2] = ft_atoi(map->char_c_rgb[2]);
	}
}

void	ft_get_color_c(char **tab, t_map *map)
{
	int y;
	int checked;

	y = 0;
	free(tab[0]);
	if (tab[1] != 0)
	{
		checked = ft_check_tab(tab[1]);
		map->char_c_rgb = ft_split(tab[1], ',');
		free(tab[1]);
		free(tab);
		if (map->char_c_rgb == NULL || checked)
			ft_error(5, map);
	}
	while (map->char_c_rgb[y] != NULL)
		y++;
	if (y != 3)
		ft_error(5, map);
	ft_check_color(map, 2);
}

void	ft_get_color_f(char **tab, t_map *map)
{
	int x;
	int checked;

	x = 0;
	free(tab[0]);
	if (tab[1] != 0)
	{
		checked = ft_check_tab(tab[1]);
		map->char_f_rgb = ft_split(tab[1], ',');
		free(tab[1]);
		free(tab);
		if (map->char_f_rgb == NULL || checked)
			ft_error(5, map);
	}
	while (map->char_f_rgb[x] != NULL)
		x++;
	if (x != 3)
		ft_error(5, map);
	ft_check_color(map, 1);
}

void	ft_check_color(t_map *map, int bool)
{
	int x;
	int y;

	x = -1;
	y = -1;
	if (bool == 1)
		while (++x != 3)
			ft_check_color_format(map->char_f_rgb[x], map);
	if (bool == 2)
		while (++y != 3)
			ft_check_color_format(map->char_c_rgb[y], map);
	ft_char_to_int(map, bool);
}

void	ft_check_color_format(char *str, t_map *map)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(5, map);
		i++;
	}
	if (i > 3 || ft_atoi(str) > 255)
		ft_error(5, map);
}
