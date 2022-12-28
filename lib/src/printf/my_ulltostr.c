/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ulltostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/28 22:54:12 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

static char	*my_ulltostr_getstr(unsigned long long ui, int dig)
{
	char				*str;
	unsigned long long	ui_tmp;

	str = (char *)malloc((dig + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	*(str + dig) = '\0';
	if (ui == 0)
		return (my_memset(str, '0', 1));
	while (ui > 0)
	{
		ui_tmp = ui / 10;
		dig--;
		*(str + dig) = ui - ui_tmp * 10 + '0';
		ui = ui_tmp;
	}
	if (dig > 0)
		*str = '-';
	return (str);
}

static int	my_ulltostr_getdigs(unsigned long long ui)
{
	int		dig;

	dig = 1;
	while (ui >= 10)
	{
		dig++;
		ui = ui / 10;
	}
	return (dig);
}

char	*my_ulltostr(unsigned long long ui)
{
	char	*str;
	int		dig;

	dig = my_ulltostr_getdigs(ui);
	str = my_ulltostr_getstr(ui, dig);
	return (str);
}
