/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 20:44:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/28 22:57:41 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libc.h"

char	*my_substr(char const *s, unsigned int start, size_t len)
{
	void	*s2;
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	len_s = my_strlen(s);
	if (start >= len_s)
		len = 0;
	else if (start + len > len_s)
		len = len_s - start;
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	my_strlcpy(s2, s + start, len + 1);
	return (s2);
}
