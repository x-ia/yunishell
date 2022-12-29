/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 17:13:53 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 16:04:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libc.h"

void	*my_memcpy(void *dst, const void *src, size_t n)
{
	void	*dst_end;

	if (dst == NULL || src == NULL || n == 0)
		return (dst);
	dst_end = dst + --n;
	while (dst <= dst_end)
		*(unsigned char *)(dst++) = *(unsigned char *)(src++);
	return (dst_end - n);
}
