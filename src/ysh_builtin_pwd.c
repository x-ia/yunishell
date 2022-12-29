/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_builtin_pwd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:08:21 by                   #+#    #+#             */
/*   Updated: 2022/12/29 13:44:50 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

int	ysh_builtin_pwd(char *argv[])
{
	char	buf[PATH_MAX + 1];

	if (argv == NULL)
		return (0);
	errno = 0;
	my_putendl_fd(getcwd(buf, PATH_MAX), STDERR_FILENO);
	return (errno);
}
