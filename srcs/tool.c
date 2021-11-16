/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:38:12 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/18 10:24:00 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_get_multiple_plus(int x, int m)
{
	if (x % m != 0)
		return (ft_get_multiple_plus(x + 1, m));
	return (x);
}

int		ft_get_multiple_minus(int x, int m)
{
	if (x % m != 0)
		return (ft_get_multiple_minus(x - 1, m));
	return (x);
}

int		ft_get_multiple(int x, int m)
{
	int a;
	int b;

	a = ft_get_multiple_plus(x, m);
	b = ft_get_multiple_minus(x, m);
	if (a - x >= x - b)
		return (b);
	else
		return (a);
}

void	ft_resolution(t_map *map, t_window *win)
{
	map->x_res = ft_get_multiple(map->x_res, 64);
	map->y_res = ft_get_multiple(map->y_res, 64);
	if (win->size_x < map->x_res)
		map->x_res = win->size_x;
	if (win->size_y < map->y_res)
		map->y_res = win->size_y;
}
