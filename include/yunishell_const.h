/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yunishell_const.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:51:23 by                   #+#    #+#             */
/*   Updated: 2022/12/29 14:22:03 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D042FB5E_6367_4D7C_8607_8D9B94440981
#define D042FB5E_6367_4D7C_8607_8D9B94440981

#ifndef YUNISHELL_CONST_H
# define YUNISHELL_CONST_H

# define CHR_DIR		'/'
# define CHR_HOME		'~'
# define CHR_SEP		':'
# define ERR_NOERR		0
# define ERR_CHDIR		1
# define ERR_SYNTAX		2
# define FD_INVALID		-1
# define SIZE_INVALID	-1
# define FLAG_STRING	0x10
# define FLAG_IN		0x20
# define FLAG_HEREDOC	0x22
# define FLAG_OUT		0x40
# define FLAG_APPEND	0x44
# define FLAG_PIPE		0x80

#endif
