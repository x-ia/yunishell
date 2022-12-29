/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ysh_sighandler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:04:04 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 14:26:48 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "yunishell.h"

//static volatile sig_atomic_t	g_signum = SIG_NONE;

void	ysh_sighandler_rl(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGQUIT)
		ysh_builtin_exit(NULL);
	if (signum == SIGINT)
	{
		rl_replace_line("", 0);
		my_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

//	write(2, my_itoa(info->si_pid), 6);
//	write(2, STR_INFO, my_strlen(STR_INFO));
//	g_signum = signum;

void	ysh_sighandler_rl_heredoc(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signum == SIGINT)
	{
		close(0);
	}
}

/*		my_putchar_fd('\x18', 0);
		my_putchar_fd('\x1b', 0);
		my_putchar_fd('\n', 0);
		my_putchar_fd('\x18', 1);
		my_putchar_fd('\x1b', 1);
		my_putchar_fd('\n', 1);
		my_putchar_fd('\x18', 3);
		my_putchar_fd('\x1b', 3);
		my_putchar_fd('\n', 3);
		my_putchar_fd('\x18', 4);
		my_putchar_fd('\x1b', 4);
		my_putchar_fd('\n', 4);*/

void	ysh_sighandler_exec(int signum, siginfo_t *info, void *context)
{
	t_cmd	*cur;

	(void)context;
	(void)info;
	if (signum == SIGQUIT || signum == SIGINT)
	{
		cur = g_shell.cmd;
		while (cur != NULL)
		{
			kill(cur->pid, signum);
			cur = cur->next;
		}
		if (signum == SIGQUIT)
			my_putendl_fd("Quit: 3", 1);
	}
}
