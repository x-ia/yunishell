/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_lexer_tokenlen.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:54:46 by                   #+#    #+#             */
/*   Updated: 2022/12/29 15:25:36 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

size_t	ysh_lexer_tokenlen_delim(char *line)
{
	int		ch;
	size_t	pos;

	if (!my_strchr(&CHRS_DELIM[1], *line))
		return (0);
	ch = *line;
	pos = 0;
	while (*(line + pos) == ch)
		pos++;
	return (pos);
}

size_t	ysh_lexer_tokenlen_quoted(char *line)
{
	int		ch;
	char	*line_end;

	if (!my_strchr(&CHRS_QUOTE[1], *line))
		return (0);
	ch = *line;
	line_end = my_strchr(line + 1, ch);
	if (!line_end)
		return (1);
	return (line_end - line + 1);
}

size_t	ysh_lexer_tokenlen_plain(char *line)
{
	size_t		i;

	i = 0;
	while (line[i] && !my_strchr(CHRS_QUOTE, line[i]))
		i++;
	return (i);
}

size_t	ysh_lexer_tokenlen(char *line)
{
	size_t	pos;

	pos = 0;
	if (line == NULL || *line == '\0')
		return (0);
	else if (my_strchr(&CHRS_DELIM[1], *(line + pos)))
		return (ysh_lexer_tokenlen_delim(line + pos));
	while (*(line + pos))
	{
		if (my_strchr(&CHRS_QUOTE[1], *(line + pos)))
			pos += ysh_lexer_tokenlen_quoted(line + pos);
		else if (my_strchr(CHRS_DELIM, *(line + pos)))
			return (pos);
		else
			pos++;
	}
	return (pos);
}
