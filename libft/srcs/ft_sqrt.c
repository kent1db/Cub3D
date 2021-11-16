/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:42:42 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/16 15:48:52 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_sqrt(double nb)
{
	double i;
	double n;

	n = 0.0;
	i = 1.0;
	if (nb < 0.0)
		return (0.0);
	if (nb == 1.0)
		return (1.0);
	while ((i <= (nb / 2.0)) && i < 46341.0)
	{
		n = i * i;
		if (n == nb)
			return (i);
		i++;
	}
	return (0.0);
}
