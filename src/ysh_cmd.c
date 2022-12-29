/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 03:00:50 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 16:03:20 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_utils.h"

void	ysh_cmd_addback(t_cmd **cmd, t_cmd *new)
{
	t_list	*prev;

	if (cmd == NULL)
		cmd = &new;
	else if (*cmd == NULL)
		*cmd = new;
	else
	{
		prev = my_lstlast(*cmd);
		prev->next = new;
	}
}

void	*ysh_cmd_clear(t_cmd **cmd)
{
	t_cmd	*ele;
	void	*next;

	if (cmd == NULL)
		return ;
	ele = *cmd;
	while (ele != NULL)
	{
		free(ele->path)
		free(ele->fd_in)
		free(ele->fd_out)
		my_mapclear(ele->arg);
		ele = ele->next;
	}
	*cmd = NULL;
	return (NULL);
}

int	ysh_cmd_size(t_cmd *cmd)
{
	int	size;

	size = 0;
	while (cmd != NULL)
	{
		size++;
		cmd = cmd->next;
	}
	return (size);
}
