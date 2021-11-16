/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:00:51 by qurobert          #+#    #+#             */
/*   Updated: 2020/11/23 11:10:41 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_islower_r(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

static int		ft_isupper_r(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int				ft_isalpha(int c)
{
	return (ft_isupper_r(c) || ft_islower_r(c));
}
