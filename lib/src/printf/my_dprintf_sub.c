/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_dprintf_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/28 22:54:12 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

int	my_dprintf_sub(int fd, const char *format, va_list *ap)
{
	t_len	*lens;
	ssize_t	ret;

	lens = (t_len *)malloc(sizeof(t_len));
	if (lens == NULL)
		return (0);
	lens->pos = 0;
	lens->ret_tmp = 0;
	lens->len = my_strlen(format);
	while (lens->pos < lens->len)
	{
		lens->ret_tmp += prf_putplane(fd, format, &(lens->pos));
		if (lens->pos < lens->len - 1)
			lens->ret_tmp += prf_conv(fd, format, ap, lens);
	}
	ret = lens->ret_tmp;
	free(lens);
	return (ret);
}
