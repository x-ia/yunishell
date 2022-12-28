/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/28 22:59:46 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mylib.h"

int	main(int argc, char *argv[])
{
	char	*str;

	errno = 0;
	str = "Hello World";
	if (argc > 1)
		str = argv[1];
	my_dprintf(2, "ret: %d\t", \
		my_printf("argc: %d\t", argc));
	my_dprintf(2, "ret: %d\t", \
		my_printf("my_strlen(\"%s\"): %zu\v", str, my_strlen(str)));
	my_dprintf(2, "ret: %d\t", \
		my_printf("errno: %d\n", errno));
	return (errno);
}
