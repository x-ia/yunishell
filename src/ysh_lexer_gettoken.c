/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_lexer_gettoken.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:47:24 by                   #+#    #+#             */
/*   Updated: 2022/12/29 15:24:09 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

int	ysh_lexer_gettoken_classify(char *line)
{
	int		flag;

	if (line == NULL)
		return (0x00);
	if (!my_strchr(CHRS_DELIM, *line))
		return (0x10);
	flag = 0;
	if (*line == CHRS_DELIM[1])
		flag = 0x20;
	else if (*line == CHRS_DELIM[2])
		flag = 0x40;
	else if (*line == CHRS_DELIM[3])
		flag = 0x80;
	if (*(line + 1) == '\0')
		return (flag);
	else if (*line == *(line + 1))
		flag += flag >> 4;
	if (*(line + 2) == '\0' && *(line + 1) != CHRS_DELIM[3])
		return (flag);
	return (0x00);
}

void	ysh_lexer_gettoken(t_token *token, char *line)
{
	char	*str;
	size_t	pos;
	size_t	len;
	size_t	i;

	pos = 0;
	i = 0;
	while (*(line + pos) != '\0')
	{
		while (*(line + pos) == CHRS_DELIM[0])
			pos++;
		len = ysh_lexer_tokenlen(line + pos);
		str = my_substr(line, pos, len);
		if (str == NULL)
			exit(ENOMEM);
		token[i].flag = ysh_lexer_gettoken_classify(str);
		token[i].str = ysh_lexer_string(str);
		free(str);
		pos += len;
		if (token[i].str != NULL)
			i++;
	}
	token[i].str = NULL;
	return ;
}
