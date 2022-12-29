/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yunishell_string.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:51:23 by                   #+#    #+#             */
/*   Updated: 2022/12/29 14:24:12 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef YUNISHELL_STRING_H
# define YUNISHELL_STRING_H

# define CHRS_DELIM			" <>|"
# define CHRS_QUOTE			"$\"'"
# define ENV_HOME			"HOME"
# define ENV_PWD			"PWD"
# define ENV_PATH			"PATH"
# define ENV_OLDPWD			"OLDPWD"
# define MSG_NOCD			"OLDPWD not set"
# define MSG_NODIR			"No such file or directory"
# define MSG_EXIT			"exit"
# define MSG_EXIT_ARG		"numeric argument required"
# define MSG_HEREDOC_EOF	"here-document delimited by end-of-file"
# define MSG_SYNTAX			"syntax error"
# define PROMPT_INIT		"ysh $ "
# define PROMPT_NEXT		"> "
# define STR_DIR			"/"
# define CMD_CD				"cd"

#endif
