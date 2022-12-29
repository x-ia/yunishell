/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:08:21 by                   #+#    #+#             */
/*   Updated: 2022/12/29 14:07:31 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

void	ysh_builtin_exec(t_cmd *cmd, int (*builtin)(char *arg[]))
{

}

int	(*ysh_builtin_getfunc(char *arg))(char *argv[])
{
	if (my_strcmp(arg, CMD_ECHO) == 0)
		return (ysh_builtin_echo);
	else if (my_strcmp(arg, CMD_CD) == 0)
		return (ysh_builtin_cd);
	else if (my_strcmp(arg, CMD_PWD) == 0)
		return (ysh_builtin_pwd);
	else if (my_strcmp(arg, CMD_EXPORT) == 0)
		return (ysh_builtin_export);
	else if (my_strcmp(arg, CMD_UNSET) == 0)
		return (ysh_builtin_unset);
	else if (my_strcmp(arg, CMD_ENV) == 0)
		return (ysh_builtin_env);
	else if (my_strcmp(arg, CMD_EXIT) == 0)
		return (ysh_builtin_exit);
	return (NULL);
}
