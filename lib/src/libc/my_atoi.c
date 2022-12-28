/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 20:57:55 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/28 22:57:41 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libc.h"

static unsigned long	my_atoi_calc(const char *str, int i, int is_minus)
{
	unsigned long	nb;
	int				i_end;

	nb = 0;
	i_end = i + 19;
	while (*(str + i) >= '0' && *(str + i) <= '9' && i < i_end)
	{
		nb = nb * 10 + *(str + i) - '0';
		i++;
	}
	if (*(str + i) >= '0' && *(str + i) <= '9')
	{
		if (nb > LONG_MAX / 10)
			nb = LONG_MAX + is_minus;
		else
			nb = nb * 10 + *(str + i) - '0';
	}
	return (nb);
}

int	my_atoi(const char *str)
{
	int				i;
	unsigned long	nb;
	int				is_minus;

	i = 0;
	while (*(str + i) == ' ' || (*(str + i) >= 9 && *(str + i) <= 13))
		i++;
	is_minus = (*(str + i) == '-');
	if (*(str + i) == '+' || *(str + i) == '-')
		i++;
	nb = my_atoi_calc(str, i, is_minus);
	if (nb > LONG_MAX + (unsigned long)is_minus)
		return (-1 + is_minus);
	if (is_minus)
		return (-nb);
	return (nb);
}
