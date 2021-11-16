/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:04:04 by qurobert          #+#    #+#             */
/*   Updated: 2021/01/06 13:30:04 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_puts_minus(int *ret, char *str, t_flags *arg, int len)
{
	int			i;

	i = 0;
	if (arg->prec == 0)
	{
		(*ret) += ft_puts(str);
		i = len;
	}
	else
	{
		while ((i < (arg->prec)) && str[i])
		{
			ft_putchar_fd(str[i++], 1);
			(*ret)++;
		}
	}
	while (i < (arg->width))
	{
		ft_putchar_fd(' ', 1);
		(*ret)++;
		i++;
	}
}

static void		ft_puts_none(int *ret, char *str, t_flags *arg, int len)
{
	int			count;
	int			i;

	i = 0;
	if (arg->prec >= len || arg->prec == 0)
		count = arg->width - len;
	else
		count = arg->width - arg->prec;
	while (count > 0)
	{
		ft_putchar_fd(arg->to_print, 1);
		count--;
		(*ret)++;
	}
	if (arg->prec == 0)
	{
		(*ret) += ft_puts(str);
		i = len;
	}
	while ((i < (arg->prec)) && str[i])
	{
		ft_putchar_fd(str[i++], 1);
		(*ret)++;
	}
}

static	void	ft_puts_width(int *ret, t_flags *arg)
{
	int			count;

	count = 0;
	while (count < arg->width)
	{
		count++;
		(*ret) += ft_putc(arg->to_print, 1);
	}
}

void			ft_print_string(va_list ap, int *ret, t_flags *arg)
{
	char		*str;
	int			len;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	if (arg->zero && !(arg->minus))
		arg->to_print = '0';
	else
		arg->to_print = ' ';
	if (arg->prec == -1)
		ft_puts_width(ret, arg);
	else if (arg->minus)
	{
		len = ft_strlen(str);
		ft_puts_minus(ret, str, arg, len);
	}
	else
	{
		len = ft_strlen(str);
		ft_puts_none(ret, str, arg, len);
	}
}
