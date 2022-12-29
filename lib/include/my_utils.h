/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 16:04:33 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_UTILS_H
# define MY_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "my_libc.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	my_putnbr_fd(int n, int fd);
t_list	*my_lstnew(void *content);
void	my_lstadd_front(t_list **lst, t_list *new);
int		my_lstsize(t_list *lst);
t_list	*my_lstlast(t_list *lst);
void	my_lstadd_back(t_list **lst, t_list *new);
void	my_lstdelone(t_list *lst, void (*del)(void*));
void	my_lstclear(t_list **lst, void (*del)(void*));
void	my_lstiter(t_list *lst, void (*f)(void *));
t_list	*my_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
size_t	my_wcslen(const char *str);
int		my_isxdigit(int c);
char	*my_ulltostr(unsigned long long ui);
char	*my_lltostr(long long n);

#endif
