/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:09:04 by qurobert          #+#    #+#             */
/*   Updated: 2020/11/23 11:10:51 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *current;

	if (*lst == NULL || lst == NULL)
		return ;
	if (del == NULL)
		return ;
	while ((*lst) != NULL)
	{
		current = (*lst);
		(*del)(current->content);
		*lst = (*lst)->next;
		free(current);
	}
	*lst = NULL;
}
