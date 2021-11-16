/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 12:40:59 by qurobert          #+#    #+#             */
/*   Updated: 2020/12/02 12:41:03 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int i;

	i = 0;
	if (tab[i] == NULL)
		return ;
	if (tab[i + 1] != NULL)
		i++;
	else
		return ;
	while (tab[i] != NULL)
	{
		if (cmp(tab[i - 1], tab[i]) > 0)
		{
			ft_swap_str(&tab[i - 1], &tab[i]);
			i = 0;
		}
		i++;
	}
}
