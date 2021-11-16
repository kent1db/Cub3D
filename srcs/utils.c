/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:12:25 by qurobert          #+#    #+#             */
/*   Updated: 2021/01/29 10:37:27 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int			ft_press(int keycode)
{
	if (keycode == 53)
	{
		ft_close(0);
		return (1);
	}
	return (0);
}

int			ft_str_search(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	if (str[i] == c)
		return (1);
	return (0);
}

int			ft_strslen(char **strs)
{
	int		i;

	i = 0;
	if (!strs)
		return (0);
	while (strs[i] != NULL)
		i++;
	return (i);
}

char		**ft_strsjoin(char const *s1, char **tab)
{
	char	**strs;
	int		i;
	int		l_str;
	int		l_strs;

	i = 0;
	if (!s1)
		return (NULL);
	l_str = ft_strlen(s1);
	l_strs = ft_strslen(tab);
	if (!(strs = malloc(sizeof(char *) * (l_strs + 2))))
		return (NULL);
	while (tab && tab[i] != NULL)
	{
		strs[i] = ft_strdup(tab[i]);
		i++;
	}
	strs[i] = ft_strdup(s1);
	strs[i + 1] = NULL;
	ft_free_tab(tab);
	return (strs);
}

char		**ft_strsdup(char **tab)
{
	int		i;
	int		len;
	char	**strs;

	i = 0;
	len = ft_strslen(tab);
	if (!(strs = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (i != len)
	{
		strs[i] = ft_strdup(tab[i]);
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
