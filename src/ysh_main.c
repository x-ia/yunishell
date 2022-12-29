/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:08:21 by                   #+#    #+#             */
/*   Updated: 2022/12/29 15:24:55 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_token	*token;
	t_cmd	*cmd;

	(void)argc;
	(void)argv;
	ysh_env_init(envp);
	while (true)
	{
		line = ysh_readline();
		if (line == NULL)
			break ;
		if (*line)
		{
			token = ysh_lexer(line);
			cmd = ysh_parser(token);
			if (cmd != NULL)
				ysh_exec(cmd);
		}
	}
	ysh_builtin_exit(NULL);
	return (g_env.status);
}
