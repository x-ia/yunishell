/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yunishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:51:23 by                   #+#    #+#             */
/*   Updated: 2022/12/29 14:09:26 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YUNISHELL_H
# define YUNISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <signal.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include <limits.h>
# include <errno.h>
# include <string.h>
# include "mylib.h"
# include "yunishell_const.h"
# include "yunishell_type.h"
# include "yunishell_string.h"

extern t_shell	g_env;

void	ysh_env_init(char *envp[]);
void	ysh_sigset_rl(void);
void	ysh_sigset_rl_heredoc(void);
void	ysh_sigset_exec(void);
void	ysh_sigset_noquit(void);
void	ysh_sigset_int(void);
void	ysh_sighandler_rl(int signum, siginfo_t *info, void *context);
void	ysh_sighandler_rl_heredoc(int signum, siginfo_t *info, void *context);
void	ysh_sighandler_exec(int signum, siginfo_t *info, void *context);

t_token	*ysh_lexer(char *line);
size_t	ysh_lexer_tokensize(char *line);

void	ysh_lexer_gettoken(t_token *token, char *line);
int		ysh_lexer_gettoken_classify(char *line);

size_t	ysh_lexer_tokenlen(char *line);
size_t	ysh_lexer_tokenlen_delim(char *line);
size_t	ysh_lexer_tokenlen_quoted(char *line);
size_t	ysh_lexer_tokenlen_plain(char *line);

char	*ysh_lexer_string(char *line);

t_cmd	*ysh_parser(t_token *token);
t_cmd	*ysh_parser_cmdnew(t_token *token, size_t *idx);
char	**ysh_parser_cmdnew_arg(t_token *token, size_t i_token);
size_t	ysh_parser_cmdnew_arg_size(t_token *token, size_t idx);
size_t	ysh_parser_cmdnew_fdsize(t_token *token, size_t idx, int flag);
t_fd	*ysh_parser_cmdnew_input(t_token *token, size_t i_token);
t_fd	*ysh_parser_cmdnew_output(t_token *token, size_t i_token);

bool	ysh_isenvchar(int c);
char	*ysh_search_env(char *env_key);
t_list	*ysh_expand_envvar(char *line, size_t *pos, size_t len);
t_list	*ysh_expand_envvar_dquote(char *line, size_t len);
char	*ysh_getenv_line(char *env_key);
char	*ysh_getenv_val(char *env_key);
bool	ysh_is_same_envkey(char *dest, char *src);
bool	ysh_is_validenv(char *env_candidate);

void	*ysh_lstclear_return_null(t_list **head);
void	ysh_lstadd_back_substr(t_list **head, char *line, \
								size_t pos, size_t len);
char	*ysh_linkedls_to_str(t_list *head);

char	*ysh_getpath_cmd(char *name);
char	*ysh_getpath_relative(char *name);
char	*ysh_getpath_envpath(char *name);
char	*ysh_getpath_join(char *dirpath, char *name);
void	ysh_setpath_home(char *path, char *arg);
void	ysh_setpath_absolute(char *path, char *arg);
void	ysh_setpath_relative(char *path, char *arg);

void	ysh_exec_in_child_process(t_cmd *cmd);
void	ysh_exec_a_builtin(t_cmd *cmd, int (*builtin)(char *arg[]));

void	ysh_fd_close(int fd[2]);
void	ysh_fd_copy(int dest[2], int src[2]);
int		ysh_fd_last_fd(t_fd *fd_lst);
void	ysh_fd_close_all_cmd(t_cmd *cmd);
void	ysh_fd_close_fds(t_fd *fd);
void	ysh_init_fd(int fd[2]);

int		(*ysh_builtin_getfunc(char *arg))(char *argv[]);
int		ysh_builtin_cd(char *argv[]);
int		ysh_builtin_echo(char *argv[]);
int		ysh_builtin_env(char *argv[]);
int		ysh_builtin_exit(char *argv[]);
int		ysh_builtin_export(char *argv[]);
void	ysh_search_env_and_set(char *env_key);
int		ysh_builtin_pwd(char *argv[]);
int		ysh_builtin_unset(char *argv[]);

size_t	ysh_strlst_count(char *str_lst[]);
void	ysh_strlst_cpy(char **dest, char **src);
void	ysh_strlst_free(char *argv[]);
char	**ysh_lst2map(t_list *lst);

bool	ysh_strisdigit(char *str);
void	*free_and_return(void *malloc_obj);
void	*print_err_set_status_return_null(char *str, int status);
void	*ysh_clear_cmd_and_return_null(t_cmd *head);
bool	ysh_is_directory(char *path);

#endif
