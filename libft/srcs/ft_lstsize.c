/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 09:22:54 by qurobert          #+#    #+#             */
/*   Updated: 2020/11/23 11:10:58 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_lstsize(t_list *lst)
{
	int		c;
	t_list	*tmp;

	c = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		c++;
		tmp = tmp->next;
	}
	return (c);
}
