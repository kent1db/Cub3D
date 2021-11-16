/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:54:03 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/02 12:34:00 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_reverse_string_itoa(char *buf)
{
	int			i;
	int			n;
	char		temp;

	i = 0;
	n = ft_strlen(buf);
	if (buf[0] == '-')
		i++;
	while (i < n)
	{
		temp = buf[i];
		buf[i] = buf[n - 1];
		buf[n - 1] = temp;
		i++;
		n--;
	}
	return (buf);
}

static int		ft_malloc_size_itoa(long int nbr)
{
	int			i;
	int			len;

	len = 10;
	i = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		i++;
	}
	while (nbr >= len)
	{
		nbr = nbr / len;
		i++;
	}
	if (nbr >= 0 && nbr < len)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char		*buf;
	long int	nbr;
	int			i;

	nbr = n;
	i = 0;
	if (!(buf = malloc(sizeof(char) * (ft_malloc_size_itoa(nbr) + 1))))
		return (NULL);
	if (nbr < 0)
	{
		buf[i++] = '-';
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		buf[i++] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	buf[i++] = (nbr % 10) + '0';
	buf[i] = '\0';
	return (ft_reverse_string_itoa(buf));
}
