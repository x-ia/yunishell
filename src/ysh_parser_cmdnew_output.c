/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_parser_cmdnew_output.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:28:00 by                   #+#    #+#             */
/*   Updated: 2022/12/29 14:56:03 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

static bool	\
	ysh_parser_cmdnew_output_sub(int *fds, t_token *token, size_t *i_token)
{
	ssize_t	i_fd;

	i_fd = 0;
	while (token[*i_token].str != NULL && token[*i_token].flag != FLAG_PIPE)
	{
		if ((token[*i_token].flag & FLAG_OUT) == FLAG_OUT)
		{
			if (token[*i_token].flag == FLAG_APPEND)
				fds[i_fd].fd = open(token[++(*i_token)].str, \
										O_WRONLY | O_CREAT | O_APPEND, 0666);
			else
				fds[i_fd].fd = open(token[++(*i_token)].str, \
										O_WRONLY | O_CREAT | O_TRUNC, 0666);
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

int	*ysh_parser_cmdnew_output(t_token *token, size_t i_token)
{
	int		*fds;
	ssize_t	size;

	size = ysh_parser_cmdnew_fdsize(token, i_token, FLAG_OUT);
	if (size == SIZE_INVALID)
		return (ysh_return_null(ERR_SYNTAX, MSG_SYNTAX));
	fds = (int_least64_t *)malloc((size + 1) * sizeof(int));
	if (fds == NULL)
		exit(EXIT_FAILURE);
	errno = 0;
	if (!ysh_parser_output_sub(fds, token, &i_token))
	{
		free(fds);
		if (errno == ERR_NOERR)
			return (ysh_return_null(ERR_NOERR, NULL));
		return (ysh_return_null(ERR_OPEN, strerror(errno)));
	}
	return (fds);
}
