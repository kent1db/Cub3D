/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:12:29 by qurobert          #+#    #+#             */
/*   Updated: 2020/11/23 11:11:27 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char const *set, char c)
{
	int		i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count(char const *s1, char const *set)
{
	int		c;
	int		start;
	int		end;

	c = 0;
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_is_set(set, s1[start]))
		start++;
	if (s1[start] == '\0')
		return (0);
	while (end > 0 && ft_is_set(set, s1[end]))
		end--;
	return (end - start + 1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		c;
	int		start;
	int		end;
	int		i;
	char	*str;

	start = 0;
	i = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1) - 1;
	c = ft_count(s1, set);
	if (!(str = malloc(sizeof(char) * (c + 1))))
		return (NULL);
	while (s1[start] && ft_is_set(set, s1[start]))
		start++;
	while (end > 0 && ft_is_set(set, s1[end]))
		end--;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
