/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_lexer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:53:14 by                   #+#    #+#             */
/*   Updated: 2022/12/29 12:35:45 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

size_t	ysh_lexer_tokensize(char *line)
{
	size_t	size;
	size_t	pos;
	size_t	len;

	if (line == NULL)
		return (0);
	size = 0;
	pos = 0;
	while (*(line + pos) != '\0')
	{
		while (*(line + pos) == CHRS_DELIM[0])
			pos++;
		len = ysh_lexer_tokenlen(line + pos);
		if (len > 0)
			size++;
		pos += len;
	}
	return (size);
}

t_token	*ysh_lexer(char *line)
{
	t_token	*token;
	size_t	size;

	size = ysh_lexer_tokensize(line);
	token = (t_token *)malloc((size + 1) * sizeof(t_token));
	if (token == NULL)
		exit(ENOMEM);
	ysh_lexer_gettoken(token, line);
	return (token);
}
