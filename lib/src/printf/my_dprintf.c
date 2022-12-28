/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/28 22:46:39 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

int	my_dprintf(int fd, const char *format, ...)
{
	va_list	ap[2];
	ssize_t	ret;

	errno = 0;
	va_start(ap[0], format);
	va_copy(ap[1], ap[0]);
	ret = my_dprintf_sub(fd, format, ap);
	va_end(ap[1]);
	va_end(ap[0]);
	if (ret > INT_MAX || errno != 0)
		return (ERR_PRF);
	return (ret);
}
