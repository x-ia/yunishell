/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 03:00:50 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 16:03:20 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_utils.h"

void	my_lstclear(t_list **lst, void (*del)(void*))
{
	void	*next;
	t_list	*ele;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		ele = *lst;
		next = ele->next;
		my_lstdelone(*lst, (*del));
		*lst = next;
	}
	lst = NULL;
}
