/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_puts_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:44:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 16:04:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libc.h"

void	my_puts_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	my_putstr_fd(s, fd);
	my_putchar_fd('\n', fd);
}
