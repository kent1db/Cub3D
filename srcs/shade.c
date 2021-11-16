/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:56:43 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/17 16:18:32 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_shade_color(int *color, t_ray *ray)
{
	if (ray->line_height <= 150)
		*color = (*color >> 1) & 8355711;
	if (ray->line_height <= 100)
		*color = (*color >> 1) & 8355711;
}
