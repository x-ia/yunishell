/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:08:21 by                   #+#    #+#             */
/*   Updated: 2022/12/29 15:24:55 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

char	*ysh_readline(void)
{
	char	*line;

	ysh_sigset_noquit();
	ysh_sigset_rl();
	line = readline(PROMPT_INIT);
	if (line == NULL)
		return (NULL);
	add_history(line);
	return (line);
}

//	rl_replace_line("", 0);
//	rl_on_new_line();
//	rl_redisplay();
//	rl_clear_history();
