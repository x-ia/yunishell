/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_parser_cmdnew_fdsize.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:28:00 by                   #+#    #+#             */
/*   Updated: 2022/12/29 14:58:28 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

size_t	ysh_parser_cmdnew_fdsize(t_token *token, size_t idx, int flag)
{
	ssize_t	size;

	size = 0;
	while (token[idx].str != NULL && token[idx].flag != FLAG_PIPE)
	{
		if ((token[idx++].flag & flag) == flag)
		{
			if (token[idx++].flag != FLAG_STRING)
				return (SIZE_INVALID);
			size++;
		}
	}
	return (size);
}
