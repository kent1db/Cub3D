/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 11:22:44 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/17 13:30:59 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub.h"

void		ft_open_file(char *filename, t_map *map)
{
	int		fd;

	if (((fd = open(filename, O_RDONLY)) == -1))
		ft_error(2, map);
	else
		ft_parse(fd, map);
}

void		ft_check_arg(int ac, char **av, t_map *map, t_ray *ray)
{
	int i;
	int len;

	i = 0;
	if (ac == 1 || ac > 3)
		ft_error(22, map);
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "--save", 7) != 0)
			ft_error(22, map);
		else
			ray->screen = 1;
	}
	len = ft_strlen(av[1]) - 4;
	if (ft_strncmp(&av[1][len], ".cub", 5) != 0)
		ft_error(79, map);
	else
		ft_open_file(av[1], map);
}

int			main(int ac, char **av)
{
	t_window	arg;
	t_map		map;
	t_ray		ray;
	t_data		data;
	t_sprt		sprt;

	arg.mlx = mlx_init();
	ft_fill_struct(&map);
	ft_init_struct(&arg, &map, &ray, &data);
	ft_check_arg(ac, av, &map, &ray);
	ft_init_compass(&ray, &data);
	ft_init_sprite_struct(&sprt, &ray, &map);
	ft_init_raycasting(&ray, &map);
	ft_init_mlx(&arg, &map, &data, &sprt);
	ft_raycasting_loop(&ray, &map, &data, &sprt);
	if (ray.screen)
		ft_screen(&ray);
	mlx_hook(arg.win, 2, 0, ft_input_on, &ray);
	mlx_hook(arg.win, 3, 0, ft_input_off, &ray);
	mlx_hook(arg.win, 17, 0L, ft_close, &arg);
	free(sprt.sprite);
	mlx_loop_hook(arg.mlx, ft_game, &ray);
	mlx_loop(arg.mlx);
	return (0);
}
