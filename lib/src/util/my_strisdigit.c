/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 15:35:49 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

bool	my_strisdigit(char *str)
{
	if (str == NULL || *str == '\0')
		return (false);
	while (*str)
	{
		if (!my_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}
