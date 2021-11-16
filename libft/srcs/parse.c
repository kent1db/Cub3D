/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:15:17 by qurobert          #+#    #+#             */
/*   Updated: 2021/01/06 13:29:55 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_parse_prec(char *format, va_list ap, int *i, t_flags *arg)
{
	if (format[*i] == '.')
	{
		if (format[++(*i)] == '*')
		{
			arg->prec = va_arg(ap, int);
			if (arg->prec == 0)
				arg->prec = -1;
			else if (arg->prec < 0)
				arg->prec = 0;
			(*i)++;
		}
		else if (format[*i] >= '0' && format[*i] <= '9')
		{
			arg->prec = ft_atoi(format + (*i));
			while (format[*i] >= '0' && format[*i] <= '9')
				(*i)++;
			if (arg->prec == 0)
				arg->prec = -1;
		}
		else
			arg->prec = -1;
	}
}

void	ft_parse_width(char *format, va_list ap, int *i, t_flags *arg)
{
	if (format[*i] == '*')
	{
		arg->width = va_arg(ap, int);
		if (arg->width < 0)
		{
			arg->minus = 1;
			arg->width = -(arg->width);
		}
		(*i)++;
	}
	else if (format[*i] >= '1' && format[*i] <= '9')
	{
		arg->width = ft_atoi(format + (*i));
		while (format[*i] >= '0' && format[*i] <= '9' && format[*i] != '\0')
			(*i)++;
	}
	else
		arg->width = 0;
}

void	ft_parse_flags(char *format, int *i, t_flags *arg)
{
	while (format[*i] == '0' || format[*i] == '-')
	{
		if (format[*i] == '0')
			arg->zero = 1;
		if (format[*i] == '-')
			arg->minus = 1;
		(*i)++;
	}
}

void	ft_parse_format(char *format, va_list ap, t_flags *arg, int *index)
{
	(*index)++;
	arg->zero = 0;
	arg->minus = 0;
	arg->prec = 0;
	ft_parse_flags(format, index, arg);
	ft_parse_width(format, ap, index, arg);
	ft_parse_prec(format, ap, index, arg);
}
