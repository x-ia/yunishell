/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:44:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/28 22:57:41 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libc.h"

void	my_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	my_putstr_fd(s, fd);
	my_putchar_fd('\n', fd);
}
