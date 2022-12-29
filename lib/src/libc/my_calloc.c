/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:12:17 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 16:04:11 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libc.h"

void	*my_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	prod;

	if (count == 0 || size == 0)
		prod = 1;
	else
	{
		prod = size * count;
		if (prod / size < count)
			prod = (size_t)(-1);
	}
	ptr = malloc(prod);
	if (ptr == NULL)
		return (NULL);
	my_bzero(ptr, prod);
	return (ptr);
}
