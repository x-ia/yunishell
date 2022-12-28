/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Yoshihiro Kosaka <ykosaka@student.42tok    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:03:00 by ykosaka           #+#    #+#             */
/*   Updated: 2022/12/28 22:57:41 by Yoshihiro K      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_PRINTF_H
# define MY_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <errno.h>
# include "my_libc.h"
# include "my_printf_typedef.h"
# include "my_printf_const.h"
# include "my_printf_flag.h"

int		my_printf(const char *fmt, ...);
int		my_dprintf(int fd, const char *fmt, ...);
int		my_dprintf_sub(int fd, const char *format, va_list *ap);
ssize_t	prf_conv(int fd, const char *fmt, va_list *ap, t_len *lens);
t_conv	*prf_getconv(const char *str, va_list *ap, ssize_t *pos);
t_conv	*prf_setconv(const char *str, va_list *ap, t_conv *conv);
int		prf_setconv_type(const char *str, ssize_t len);
int		prf_setconv_length(const char *str, ssize_t len, int type);
void	prf_setconv_wandp(const char *str, va_list *ap, t_conv **conv);
int		prf_setconv_flag(const char *str, ssize_t len);
int		prf_setconv_order(const char *str, ssize_t len);
int		prf_hasflag(int val, int flag);
ssize_t	prf_putlen(char *str, t_conv *conv);
ssize_t	prf_putplane(int fd, const char *s, ssize_t *pos);
ssize_t	prf_putchar(int fd, char c);
ssize_t	prf_putstr(int fd, const char *s);
ssize_t	prf_putstrn(int fd, const char *s, ssize_t len, t_conv *conv);
void	prf_shiftarg(t_conv *conv, va_list *ap);
char	*prf_convarg(t_conv *conv, va_list *ap, ssize_t ret_tmp);
char	*prf_convarg_s(char *str, t_conv *conv);
wchar_t	*prf_convarg_ws(wchar_t *str, t_conv *conv);
char	*prf_convarg_i(long long nb, t_conv *conv);
char	*prf_convarg_ui(unsigned long long nb_u, t_conv *conv);
char	*prf_convarg_p(unsigned long long nb_llu, t_conv *conv);
char	*prf_convarg_dbl(long double nb, t_conv *conv);
char	*prf_convarg_nan(t_ldbl ldbl, t_conv *conv);
char	*prf_convarg_ftoe(char *str);
char	*prf_convarg_a(double nb, t_conv *conv);
char	*prf_convarg_la(t_ldbl ldbl, t_conv *conv);
char	*prf_chrtostr(int ch);
wchar_t	*prf_wchrtostr(wint_t ch);
ssize_t	prf_getpresentret(int *ptr, ssize_t ret);
ssize_t	prf_putpadding(int fd, t_conv *conv, ssize_t len_put, short flag_tgt);
char	*prf_adjustdigit(char *str, t_conv *conv);
char	*prf_rounddigit(char *str, t_conv *conv);
t_flen	*prf_rounddigit_getlen(char *str, t_conv *conv);
char	*prf_rounddigit_fill(char *str, t_conv *conv, ssize_t len);
char	*prf_rounddigit_a(char *str, t_conv *conv);
t_flen	*prf_rounddigit_a_getlen(char *str, t_conv *conv);
char	*prf_rounddigit_a_fill(char *str, t_conv *conv, t_flen *len);
t_flen2	*prf_rounddigit_a_fill_len(t_conv *conv, t_flen *len);
char	*prf_ulltostr_o(unsigned long long n_dec, int bytes);
char	*prf_ulltostr_x(unsigned long long n_dec, int bytes);;
char	*prf_ftoa(long double nb, int precision);
void	prf_strtoupper(char *str);
size_t	my_wcslen(const char *str);
ssize_t	prf_strnchr(const char *str, char ch, ssize_t len);
ssize_t	prf_strrnchr(const char *str, char ch, ssize_t len);
char	*prf_strjoin(char const *s1, char const *s2, int flag_free);
int		prf_hexdigitadd(int c, int n);
int		my_isxdigit(int c);
int		prf_isdigit19(int c);
int		prf_isxdigit1f(int c);
char	*my_ulltostr(unsigned long long ui);
char	*my_lltostr(long long n);

#endif
