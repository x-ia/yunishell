/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:26:41 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/28 22:57:41 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libc.h"

size_t	my_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_d;
	size_t	pos_s;

	len_d = 0;
	pos_s = 0;
	if (dst != NULL || dstsize > 0)
	{
		len_d = my_strlen(dst);
		while (len_d + pos_s + 1 < dstsize && *(src + pos_s) != '\0')
		{
			*(dst + len_d + pos_s) = *(src + pos_s);
			pos_s++;
		}
		if (dstsize > 0)
			*(dst + len_d + pos_s) = '\0';
		if (dstsize < len_d)
			len_d = dstsize;
	}
	while (*(src + pos_s) != '\0')
		pos_s++;
	return (len_d + pos_s);
}
