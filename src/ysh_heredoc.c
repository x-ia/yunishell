/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_parser_cmdnew_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:28:00 by                   #+#    #+#             */
/*   Updated: 2022/12/28 21:26:27 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

static bool	ysh_heredoc_read(const char *eof, int fd)
{
	char	*buf;

	while (1)
	{
		ysh_sigset_heredoc();
		buf = readline(PROMPT_NEXT);
		if (!buf)
		{
			my_putendl_fd(MSG_HEREDOC_EOF, 2);
			return (true);
		}
		if (my_strncmp(buf, eof, INT_MAX) == 0)
		{
			free(buf);
			return (true);
		}
		my_putendl_fd(buf, fd);
		free(buf);
	}
	return (true);
}

int	ysh_heredoc(const char *eof)
{
	int	fd[2];

	pipe(fd);
	if (ysh_heredoc_read(eof, fd[1]))
	{
		close(fd[1]);
		return (fd[0]);
	}
	else
	{
		ysh_fd_close(fd);
		return (-1);
	}
}
