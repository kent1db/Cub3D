/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:41:40 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/02 12:41:42 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_base(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(char *str, char *base)
{
	int		signe;
	int		n;
	int		i;
	int		base_l;

	i = 0;
	signe = 1;
	n = 0;
	base_l = ft_strlen(base);
	if (!(ft_check_error(base)))
		return (0);
	while (ft_whitespace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			signe = -signe;
	while (str[i] && (ft_is_in_base(str[i], base) != -1))
		n = n * base_l + ft_is_in_base(str[i++], base);
	return (n * signe);
}
