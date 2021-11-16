/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:50:30 by qurobert          #+#    #+#             */
/*   Updated: 2020/11/23 11:11:19 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		c1;
	int		c2;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	c1 = ft_strlen(s1);
	c2 = ft_strlen(s2);
	if (!(str = malloc(sizeof(char) * (c1 + c2 + 1))))
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	c2 = 0;
	while (s2[c2] != '\0')
		str[i++] = s2[c2++];
	str[i] = '\0';
	return (str);
}
