/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qurobert <qurobert@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 10:47:07 by qurobert          #+#    #+#             */
/*   Updated: 2020/11/24 05:04:26 by qurobert         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*begin;

	if (lst != NULL && f != NULL)
	{
		if (!(begin = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		current = begin;
		lst = lst->next;
	}
	while (lst != NULL)
	{
		if (!(current->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		current = current->next;
		lst = lst->next;
	}
	current->next = NULL;
	return (begin);
}
