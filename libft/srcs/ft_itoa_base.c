/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:42:18 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/02 12:42:20 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(int nbr, char *base, char *buf)
{
	int			base_l;
	long int	n;
	int			i;

	i = 0;
	n = nbr;
	if (!(ft_check_error(base)))
		return (NULL);
	base_l = ft_strlen(base);
	if (n < 0)
	{
		buf[i++] = '-';
		n = -n;
	}
	while (n >= base_l)
	{
		buf[i++] = base[n % base_l];
		n = n / base_l;
	}
	buf[i++] = base[n % base_l];
	buf[i] = '\0';
	return (ft_reverse_string(buf));
}
