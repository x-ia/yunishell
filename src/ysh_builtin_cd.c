/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_builtin_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 14:08:21 by                   #+#    #+#             */
/*   Updated: 2022/12/29 15:25:36 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

int	ysh_builtin_cd_chdir(char *path)
{
	if (path == NULL)
	{
		my_putendl_fd(MSG_NOCD, STDERR_FILENO);
		return (ERR_CHDIR);
	}
	else if (chdir(path))
	{
		my_putendl_fd(MSG_NODIR, STDERR_FILENO);
		return (ERR_CHDIR);
	}
	ysh_env_set(ENV_OLDPWD, ysh_getenv_val(ENV_PWD));
	ysh_env_set(ENV_PWD, getcwd(path, PATH_MAX));
	return (ERR_NOERR);
}

int	ysh_builtin_cd(char	*argv[])
{
	char	path[PATH_MAX + 1];
	int		status;

	if (argv == NULL || argv[1] == NULL)
		return (ysh_builtin_cd_chdir(ysh_getenv_val(ENV_HOME)));
	else if (argv[1][0] == CHR_HOME \
		&& (argv[1][1] == CHR_DIR || argv[1][1] == '\0'))
		ysh_setpath_home(path, argv[1]);
	else if (!my_strncmp(argv[1], "-", PATH_MAX + 1))
		return (ysh_builtin_cd_chdir(ysh_getenv_val(ENV_OLDPWD)));
	else if (argv[1][0] == CHR_DIR)
		ysh_setpath_absolute(path, argv[1]);
	else
		ysh_setpath_relative(path, argv[1]);
	status = ysh_builtin_cd_chdir(path);
	return (status);
}
