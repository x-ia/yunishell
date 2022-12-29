/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:08:21 by                   #+#    #+#             */
/*   Updated: 2022/12/29 15:24:55 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

void	ysh_exec(t_cmd *cmd)
{
	int	(*pf_builtin)(char *arg[]);

	ysh_sigset_exec();
	ysh_sigset_noquit();
	pf_builtin = ysh_builtin_getfunc(cmd->arg[0]);
	if (pf_builtin != NULL && ysh_lstsize_cmd(cmd) == 1)
		return (ysh_builtin_exec(cmd, pf_builtin));
	else
		return (ysh_exec_child(cmd));
}
