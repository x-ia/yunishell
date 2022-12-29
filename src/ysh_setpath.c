/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_setpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:08:21 by                   #+#    #+#             */
/*   Updated: 2022/12/29 15:25:36 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

void	ysh_setpath_home(char *path, char *arg)
{
	my_strlcpy(path, ysh_getenv_val(ENV_HOME), PATH_MAX + 1);
	my_strlcat(path, &arg[1], PATH_MAX + 1);
}

void	ysh_setpath_absolute(char *path, char *arg)
{
	my_strlcpy(path, arg, PATH_MAX + 1);
}

void	ysh_setpath_relative(char *path, char *arg)
{
	my_strlcpy(path, ysh_getenv_val(ENV_PWD), PATH_MAX + 1);
	my_strlcat(path, STR_DIR, PATH_MAX + 1);
	my_strlcat(path, arg, PATH_MAX + 1);
}
