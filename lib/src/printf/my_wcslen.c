/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_wcslen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/28 22:54:12 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

size_t	my_wcslen(const char *str)
{
	const wchar_t	*wstr;
	const wchar_t	*wstr_head;

	if (str == NULL)
		return (0);
	wstr = (wchar_t *)str;
	wstr_head = wstr;
	while (*wstr != '\0')
		wstr++;
	return (wstr - wstr_head);
}
