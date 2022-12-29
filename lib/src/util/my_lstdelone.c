/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 00:46:35 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 16:03:20 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_utils.h"

void	my_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst != NULL && (*del) != NULL)
	{
		if (lst->content != NULL)
			(*del)(lst->content);
		free(lst);
	}
}
