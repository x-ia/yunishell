/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:28:00 by                   #+#    #+#             */
/*   Updated: 2022/12/29 14:47:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

bool	ysh_parser_chktokenflag(t_token *token)
{
	size_t	idx;

	idx = 0;
	if (token[idx].flag == FLAG_PIPE)
		return (false);
	while (token[idx].str != NULL)
	{
		if (token[idx].flag == 0)
			return (false);
		idx++;
	}
	if (idx > 0 && token[idx - 1].flag == FLAG_PIPE)
		return (false);
	return (true);
}

t_cmd	*ysh_parser(t_token *token)
{
	size_t	idx;
	t_cmd	*cmd;
	t_cmd	*new;

	if (!ysh_parser_chktokenflag(token))
		return (ysh_return_null(ERR_SYNTAX, MSG_SYNTAX));
	idx = 0;
	cmd = ysh_parser_cmdnew(token, &idx);
	if (cmd == NULL)
		return (NULL);
	while (token[idx++].flag == FLAG_PIPE)
	{
		new = ysh_parser_cmdnew(token, &idx);
		if (!new)
			return (ysh_clear_cmd(cmd));
		ysh_lstadd_back_cmd(cmd, new);
	}
	return (cmd);
}
