/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 14:03:51 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/28 22:57:41 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libc.h"

static void	*my_lstmap_f(t_list *lst, void *(*f)(void *))
{
	if (lst != NULL)
	{
		if ((*f) == NULL)
			return (my_lstnew(lst->content));
		return (my_lstnew((*f)(lst->content)));
	}
	return (NULL);
}

t_list	*my_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst2;
	t_list	*lst2_ele;

	if (lst == NULL)
		return (NULL);
	lst2 = NULL;
	while (lst != NULL)
	{
		lst2_ele = my_lstmap_f(lst, (*f));
		if (lst2_ele == NULL)
		{
			my_lstclear(&lst2, (*del));
			return (NULL);
		}
		my_lstadd_back(&lst2, lst2_ele);
		lst = lst->next;
	}
	return (lst2);
}
