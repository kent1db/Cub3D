/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:09:24 by qurobert          #+#    #+#             */
/*   Updated: 2021/01/06 13:30:12 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_get_percent(char *format)
{
	int		i;

	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			return (i);
		i++;
	}
	return (-1);
}

int			ft_puts(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int			ft_putc(char c, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		write(1, &c, 1);
		i++;
	}
	return (nb);
}

int			ft_putnb_pos(long nb, t_flags *arg)
{
	long	base_l;
	char	*base;

	base = "0123456789";
	base_l = 10;
	if (arg->prec == -1 && nb == 0)
		return (0);
	if (nb >= base_l)
		return (ft_putnb_pos(nb / base_l, arg) + ft_putc(base[nb % base_l], 1));
	return (ft_putc(base[nb % base_l], 1));
}

int			ft_count_int(long nb)
{
	int		count;

	count = 1;
	while (nb > 9)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}
