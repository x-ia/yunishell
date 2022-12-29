/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 15:12:17 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 16:04:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libc.h"

void	*my_memset(void *buf, int ch, size_t n)
{
	void	*buf_end;

	if (n == 0)
		return (buf);
	buf_end = buf + --n;
	while (buf <= buf_end)
		*(unsigned char *)(buf++) = (unsigned char)ch;
	return (buf_end - n);
}
