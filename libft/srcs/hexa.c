/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 15:23:38 by qurobert          #+#    #+#             */
/*   Updated: 2021/01/06 13:29:46 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_zero(int *ret, t_flags *arg)
{
	int				count;

	count = 0;
	if (arg->width)
		(*ret) += ft_putc(' ', arg->width);
}

static void			ft_puthex_minus(int *ret, unsigned int nb,
					t_flags *arg, int len)
{
	int				count_s;
	int				count_z;

	if (arg->prec > len)
		count_z = arg->prec - len;
	if (arg->prec <= len)
		count_z = 0;
	if (arg->prec >= arg->width)
		count_s = 0;
	if (arg->prec < arg->width)
	{
		if (count_z == 0)
			count_s = arg->width - len;
		else
			count_s = arg->width - arg->prec;
	}
	if (count_z > 0)
		while (count_z--)
			(*ret) += ft_putc('0', 1);
	(*ret) += ft_put_hexa(nb, arg);
	if (count_s > 0)
		while (count_s--)
			(*ret) += ft_putc(' ', 1);
}

static void			ft_puthex_zero(int *ret, unsigned int nb,
					t_flags *arg, int len)
{
	if (arg->width > len)
	{
		(*ret) += ft_putc('0', arg->width - len);
	}
	(*ret) += ft_put_hexa(nb, arg);
}

static void			ft_puthex_none(int *ret, unsigned int nb,
					t_flags *arg, int len)
{
	int				count_s;
	int				count_z;

	if (arg->prec > len)
		count_z = arg->prec - len;
	if (arg->prec <= len)
		count_z = 0;
	if (arg->prec >= arg->width)
		count_s = 0;
	if (arg->prec < arg->width)
	{
		if (count_z == 0)
			count_s = arg->width - len;
		else
			count_s = arg->width - arg->prec;
	}
	if (count_s > 0)
		while (count_s--)
			(*ret) += ft_putc(' ', 1);
	if (count_z > 0)
		while (count_z--)
			(*ret) += ft_putc('0', 1);
	(*ret) += ft_put_hexa(nb, arg);
}

void				ft_print_hexa(va_list ap, int *ret,
					t_flags *arg, char c)
{
	unsigned int	nb;
	int				len;

	nb = va_arg(ap, unsigned int);
	len = ft_count_hexa(nb);
	if (c == 'X')
		arg->hexa = 1;
	else
		arg->hexa = 0;
	if (nb == 0 && arg->prec == -1)
		ft_zero(ret, arg);
	else if (arg->minus)
		ft_puthex_minus(ret, nb, arg, len);
	else if (arg->zero && arg->prec == 0)
		ft_puthex_zero(ret, nb, arg, len);
	else
		ft_puthex_none(ret, nb, arg, len);
}
