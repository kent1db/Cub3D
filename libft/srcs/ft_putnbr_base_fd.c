/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:42:28 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/02 12:42:29 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_check_error_pn(char *base)
{
	int			i;
	int			j;

	i = 0;
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void			ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	long int	base_l;
	long int	n;

	n = nbr;
	if (!(ft_check_error_pn(base)))
		return ;
	base_l = (long int)ft_strlen(base);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= base_l)
		ft_putnbr_base_fd((n / base_l), base, fd);
	ft_putchar_fd(base[n % base_l], fd);
}
