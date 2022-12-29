/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_parser_cmdnew_input.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:28:00 by                   #+#    #+#             */
/*   Updated: 2022/12/29 14:57:23 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

static bool	\
	ysh_parser_cmdnew_input_sub(t_fd *fds, t_token *token, size_t *i_token)
{
	ssize_t	i_fd;

	i_fd = 0;
	while (token[*i_token].str != NULL && token[*i_token].flag != FLAG_PIPE)
	{
		if ((token[*i_token].flag & FLAG_IN) == FLAG_IN)
		{
			if (token[*i_token].flag == FLAG_HEREDOC)
				fds[i_fd].fd = ysh_heredoc(token[++(*i_token)].str);
			else
				fds[i_fd].fd = open(token[++(*i_token)].str, O_RDONLY);
			if (fds[i_fd].fd < 0)
				return (false);
			fds[i_fd++].path = token[*i_token].str;
		}
		(*i_token)++;
	}
	fds[i_fd].path = NULL;
	fds[i_fd].fd = FD_INVALID;
	return (true);
}

t_fd	*ysh_parser_cmdnew_input(t_token *token, size_t i_token)
{
	t_fd	*fds;
	ssize_t	size;

	size = ysh_parser_cmdnew_fdsize(token, i_token, FLAG_IN);
	if (size == SIZE_INVALID)
		return (ysh_return_null(ERR_SYNTAX, MSG_SYNTAX));
	fds = (t_fd *)malloc((size + 1) * sizeof(t_fd));
	if (fds == NULL)
		exit(EXIT_FAILURE);
	errno = 0;
	if (!ysh_parser_cmdnew_input_sub(fds, token, &i_token))
	{
		free(fds);
		if (errno == ERR_NOERR)
			return (ysh_return_null(ERR_NOERR, NULL));
		return (ysh_return_null(ERR_OPEN, strerror(errno)));
	}
	return (fds);
}
