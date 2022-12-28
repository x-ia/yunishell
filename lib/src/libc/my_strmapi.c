/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 21:44:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/28 22:57:41 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_libc.h"

char	*my_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*s2;
	size_t	len;
	size_t	i;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	i = 0;
	len = my_strlen(s);
	s2 = malloc((len + 1) * sizeof(char));
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		*(s2 + i) = (*f)(i, *(s + i));
		i++;
	}
	*(s2 + i) = '\0';
	return (s2);
}
