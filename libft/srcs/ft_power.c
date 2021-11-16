/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:33:39 by qurobert          #+#    #+#             */
/*   Updated: 2021/02/16 15:48:43 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_power(double x, unsigned int pow)
{
	if (pow == 0)
		return (1.0);
	if (pow == 1)
		return (x);
	return (x * ft_power(x, pow - 1));
}
