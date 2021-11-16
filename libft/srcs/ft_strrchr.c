/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:17:09 by qurobert          #+#    #+#             */
/*   Updated: 2020/11/23 11:11:26 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*oc;
	int		i;

	oc = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			oc = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		oc = (char *)&s[i];
	return (oc);
}
