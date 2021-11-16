/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 11:34:40 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/18 14:56:04 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int			ft_close(int bool)
{
	if (bool == 1)
	{
		exit(EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	else
	{
		exit(EXIT_SUCCESS);
		return (EXIT_SUCCESS);
	}
}

void		ft_error(int errnum, t_map *map)
{
	if (errnum == 100)
		ft_printf("Error\nIncorrect Map\n");
	else
		ft_printf("Error\n%s\n", strerror(errnum));
	ft_free_struct(map);
	ft_close(EXIT_FAILURE);
}

void		ft_free_struct(t_map *map)
{
	ft_free_tab(map->char_c_rgb);
	ft_free_tab(map->char_f_rgb);
	ft_free_tab(map->map);
	ft_free_tab(map->map_check);
	ft_free_str(map->path_e);
	ft_free_str(map->path_s);
	ft_free_str(map->path_n);
	ft_free_str(map->path_w);
	ft_free_str(map->path_sprite);
	ft_free_str(map->path_sprite_b);
}

void		ft_free_str(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
}

void		ft_free_tab(char **strs)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (strs)
		len = ft_strslen(strs);
	while (i != len)
		free(strs[i++]);
	if (strs)
	{
		free(strs);
		strs = NULL;
	}
}
