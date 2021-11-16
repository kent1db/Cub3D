/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 15:34:41 by qurobert          #+#    #+#             */
/*   Updated: 2021/01/06 13:29:51 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_zero(int *ret, t_flags *arg)
{
	int			count;

	count = 0;
	if (arg->width)
		(*ret) += ft_putc(' ', arg->width);
}

static	void	ft_put_int_minus(int *ret, long nb, t_flags *arg, int len)
{
	int			count_s;
	int			count_z;

	if (arg->prec > len)
		count_z = arg->prec - len;
	if (arg->prec <= len)
		count_z = 0;
	if (arg->prec >= arg->width)
		count_s = 0;
	if (arg->prec < arg->width)
	{
		if (count_z == 0)
			count_s = arg->width - len - arg->sign;
		else
			count_s = arg->width - arg->prec - arg->sign;
	}
	if (arg->sign)
		(*ret) += ft_putc('-', 1);
	if (count_z > 0)
		while (count_z--)
			(*ret) += ft_putc('0', 1);
	(*ret) += ft_putnb_pos(nb, arg);
	if (count_s > 0)
		while (count_s--)
			(*ret) += ft_putc(' ', 1);
}

static void		ft_put_int_zero(int *ret, long nb, t_flags *arg, int len)
{
	if (arg->sign)
		(*ret) += ft_putc('-', 1);
	if (arg->width > len + arg->sign)
	{
		(*ret) += ft_putc('0', arg->width - (len + arg->sign));
	}
	(*ret) += ft_putnb_pos(nb, arg);
}

static void		ft_put_int_none(int *ret, long nb, t_flags *arg, int len)
{
	int			count_s;
	int			count_z;

	if (arg->prec > len)
		count_z = arg->prec - len;
	if (arg->prec <= len)
		count_z = 0;
	if (arg->prec >= arg->width)
		count_s = 0;
	if (arg->prec < arg->width)
	{
		if (count_z == 0)
			count_s = arg->width - len - arg->sign;
		else
			count_s = arg->width - arg->prec - arg->sign;
	}
	if (count_s > 0)
		while (count_s--)
			(*ret) += ft_putc(' ', 1);
	if (arg->sign)
		(*ret) += ft_putc('-', 1);
	if (count_z > 0)
		while (count_z--)
			(*ret) += ft_putc('0', 1);
	(*ret) += ft_putnb_pos(nb, arg);
}

void			ft_print_int(va_list ap, int *ret, t_flags *arg)
{
	long		nb;
	int			len;

	arg->sign = 0;
	nb = (long)va_arg(ap, int);
	if (nb < 0)
	{
		arg->sign = 1;
		nb = -nb;
	}
	len = ft_count_int(nb);
	if (nb == 0 && arg->prec == -1)
		ft_zero(ret, arg);
	else if (arg->minus)
		ft_put_int_minus(ret, nb, arg, len);
	else if (arg->zero && arg->prec == 0)
		ft_put_int_zero(ret, nb, arg, len);
	else
		ft_put_int_none(ret, nb, arg, len);
}
