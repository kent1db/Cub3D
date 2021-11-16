/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 16:00:40 by qurobert          #+#    #+#             */
/*   Updated: 2021/01/06 13:29:28 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_put_hexa(unsigned int nb, t_flags *arg)
{
	unsigned int		base_l;
	char				*base;

	if (arg->hexa)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	base_l = 16;
	if (nb >= base_l)
		return (ft_put_hexa(nb / base_l, arg) + ft_putc(base[nb % base_l], 1));
	return (ft_putc(base[nb % base_l], 1));
}

int						ft_count_hexa(unsigned int nb)
{
	unsigned int		base_l;

	base_l = 16;
	if (nb >= base_l)
		return (ft_count_hexa(nb / base_l) + 1);
	return (1);
}

int						ft_put_hexa_ll(unsigned long long nb)
{
	unsigned long long	base_l;
	char				*base;

	base = "0123456789abcdef";
	base_l = 16;
	if (nb >= base_l)
		return (ft_put_hexa_ll(nb / base_l) + ft_putc(base[nb % base_l], 1));
	return (ft_putc(base[nb % base_l], 1));
}

int						ft_count_hexa_ll(unsigned long long nb)
{
	unsigned long long	base_l;
	char				*base;

	base = "0123456789abcdef";
	base_l = 16;
	if (nb >= base_l)
		return (ft_count_hexa_ll(nb / base_l) + 1);
	return (1);
}
