/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yunishell_type.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:51:23 by                   #+#    #+#             */
/*   Updated: 2022/12/29 14:46:20 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YUNISHELL_TYPE_H
# define YUNISHELL_TYPE_H

typedef struct sigaction	t_sa;

typedef struct s_token {
	char	*str;
	int		flag;
}	t_token;

typedef struct s_cmd {
	char			*path;
	char			**arg;
	int				*fd_in;
	int				*fd_out;
	struct s_cmd	*next;
	struct s_cmd	*prev;
	pid_t			pid;
}	t_cmd;

typedef struct s_shell {
	t_list	*environ;
	int		status;
	t_cmd	*cmd;
}	t_shell;

#endif
