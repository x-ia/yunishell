/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:26:41 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 16:04:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libc.h"

char	*my_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	len_h;
	size_t	len_n;

	if (haystack != NULL || len > 0)
	{
		i = 0;
		len_h = my_strlen(haystack);
		len_n = my_strlen(needle);
		if (len_h < len)
			len = len_h;
		while (i + len_n <= len)
		{
			j = 0;
			while (j < len_n && *(haystack + i + j) == *(needle + j))
				j++;
			if (j == len_n)
				return ((char *)haystack + i);
			i++;
		}
	}
	return (NULL);
}
