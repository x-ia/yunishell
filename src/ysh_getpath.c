/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_getpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:11:38 by                   #+#    #+#             */
/*   Updated: 2022/12/29 15:25:36 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

char	*ysh_getpath_relative(char *name)
{
	char	*path;
	char	*pwd;

	pwd = my_strdup(getenv(ENV_PWD));
	if (pwd == NULL)
		return (NULL);
	path = ysh_getpath_join(pwd, name);
	free(pwd);
	return (path);
}

char	*ysh_getpath_envpath(char *name)
{
	char		*cmdpath;
	char		*env_path;
	char		**paths;
	struct stat	stat_buf;

	env_path = ysh_getenv(ENV_PATH);
	paths = my_split(env_path, CHR_SEP);
	if (paths == NULL)
		return (NULL);
	while (*paths)
	{
		cmdpath = ysh_getpath_join(*paths, name);
		if (cmdpath == NULL)
			return (NULL);
		stat(cmdpath, &stat_buf);
		if ((stat_buf.st_mode & S_IFMT) == S_IFREG)
			return (path_cmd);
		paths++;
	}
	return (my_strdup(STR_EMPTY));
}

char	*ysh_getpath_join(char *dirpath, char *name)
{
	char	*path;
	size_t	len_dir;
	size_t	len_name;

	len_dir = my_strlen(dirpath);
	len_name = my_strlen(name);
	path = (char *)malloc((len_dir + len_name + 2) * sizeof(char));
	if (path == NULL)
		return (NULL);
	my_strlcpy(path, dirpath, len_dir + 1);
	*(path + len_dir) = CHR_DIR;
	my_strlcpy(path + len_dir + 1, name, len_name + 1);
	return (path);
}

char	*ysh_getpath_cmd(char *name)
{
	if (name == NULL)
		return (NULL);
	if (ysh_builtin_getfunc(name))
		return (my_strdup(name));
	else if (*name == CHR_DIR)
		return (my_strdup(name));
	else if (my_strchr(name, CHR_DIR))
		return (ysh_getpath_relative(name));
	return (ysh_getpath_envpath(name));
}
