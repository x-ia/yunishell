/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 15:26:41 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 16:04:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libc.h"

char	*my_strrchr(const char *s, int c)
{
	const char	*s_ret;

	s_ret = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			s_ret = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	if (s_ret == NULL)
		return (NULL);
	return ((char *)s_ret);
}
