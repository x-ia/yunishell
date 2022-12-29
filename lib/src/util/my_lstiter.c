/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 13:31:56 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 16:03:20 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_utils.h"

void	my_lstiter(t_list *lst, void (*f)(void *))
{
	if ((*f) != NULL)
	{
		while (lst != NULL)
		{
			if (lst->content != NULL)
				(*f)(lst->content);
			lst = lst->next;
		}
	}
}
