/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_utils.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/29 15:50:14 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIBC_H
# define MY_LIBC_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		my_isalpha(int c);
int		my_isdigit(int c);
int		my_isalnum(int c);
int		my_isascii(int c);
int		my_isprint(int c);
size_t	my_strlen(const char *str);
void	*my_memset(void *buf, int ch, size_t n);
void	my_bzero(void *s, size_t n);
void	*my_memcpy(void *dst, const void *src, size_t n);
void	*my_memmove(void *dst, const void *src, size_t n);
size_t	my_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	my_strlcat(char *dst, const char *src, size_t dstsize);
int		my_toupper(int c);
int		my_tolower(int c);
char	*my_strchr(const char *s, int c);
char	*my_strrchr(const char *s, int c);
int		my_strncmp(const char *s1, const char *s2, size_t n);
void	*my_memchr(const void *s, int c, size_t n);
int		my_memcmp(const void *s1, const void *s2, size_t n);
char	*my_strnstr(const char *haystack, const char *needle, size_t len);
int		my_atoi(const char *str);
void	*my_calloc(size_t count, size_t size);
char	*my_strdup(const char *s1);
char	*my_substr(char const *s, unsigned int start, size_t len);
char	*my_strjoin(char const *s1, char const *s2);
char	*my_strtrim(char const *s1, char const *set);
char	**my_split(char const *s, char c);
char	*my_itoa(int n);
char	*my_strmapi(char const *s, char (*f)(unsigned int, char));
void	my_striteri(char *s, void (*f)(unsigned int, char *));
void	my_putchar_fd(char c, int fd);
void	my_putstr_fd(char *s, int fd);
void	my_putendl_fd(char *s, int fd);

#endif
