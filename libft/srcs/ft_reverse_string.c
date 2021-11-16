/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:45:17 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/02 12:45:18 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_reverse_string(char *buf)
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
