/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_builtin_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:08:21 by                   #+#    #+#             */
/*   Updated: 2022/12/29 15:25:36 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

int	ysh_builtin_exit(char *argv[])
{
	int	status;

	my_putendl_fd(STDERR_FILENO, MSG_EXIT);
	if (argv == NULL || argv[0] == NULL || argv[1] == NULL)
		status = g_shell.status;
	else if (argv[2] == NULL)
	{
		if (ysh_strisdigit(argv[1]))
			status = my_atoi(argv[1]);
		else
		{
			my_putendl_fd(MSG_EXIT_ARG, STDERR_FILENO);
			status = 0xff;
		}
	}
	else
	{
		my_putendl_fd("too many arguments", 2);
		return (1);
	}
	exit(status);
}
