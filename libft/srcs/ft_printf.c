/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 15:56:41 by qurobert          #+#    #+#             */
/*   Updated: 2021/01/06 13:31:53 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_select(char conv, va_list ap, int *ret, t_flags *arg)
{
	if (conv == 'c')
		ft_print_char(ap, ret, arg);
	else if (conv == 's')
		ft_print_string(ap, ret, arg);
	else if (conv == 'p')
		ft_print_adress(ap, ret, arg);
	else if (conv == 'd' || conv == 'i')
		ft_print_int(ap, ret, arg);
	else if (conv == 'u')
		ft_print_unsigned(ap, ret, arg);
	else if (conv == 'x' || conv == 'X')
		ft_print_hexa(ap, ret, arg, conv);
	else if (conv == '%')
		ft_print_percent(ret, arg);
}

static void		ft_print(char *format, va_list ap, int *ret, t_flags *arg)
{
	int			i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_parse_format(format, ap, arg, &i);
			ft_select(format[i], ap, ret, arg);
		}
		else
		{
			write(1, &(format[i]), 1);
			(*ret)++;
		}
		if (format[i])
			i++;
	}
}

int				ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;
	t_flags		arg;

	ret = 0;
	va_start(ap, format);
	arg.len = ft_strlen(format);
	if (ft_get_percent((char *)format) == -1)
	{
		ft_putstr_fd((char *)format, 1);
		return (arg.len);
	}
	ft_print((char *)format, ap, &ret, &arg);
	va_end(ap);
	return (ret);
}
