/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:16:20 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/15 09:12:39 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <wchar.h>
# define MIN(x, y) ((x < y) ?  x : y)

typedef struct	s_flags
{
	int		hash;
	int		prec;
	int		post;
	int		neg;
	int		zero;
	int		width;
	int		space;
	int		l;
	int		h;
	int		j;
	int		z;
	char	conversion;
}				t_flags;

int				ft_printf(const char *fmt, ...);
void			ft_putchar(char c);
void			ft_putnchar(char c, size_t n);
char			*ft_strchr(const char *s, int c);
char			*ft_strnew(size_t size);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				parse_str(va_list *av, char *str);
int				check_flags(va_list *av, char **tmp);
char			*deal_flags(char *str, t_flags *flags);
int				ft_hash_flag(char *str);
int				ft_neg_flag(char *str);
int				ft_post_flag(char *str);
char			*ft_strpbrk(char *str, char *exist);
void			ft_strdel(char **as);
char			*ft_strndup(const char *s, size_t n);
int				ft_flag_zero(char *str, int neg);
char			*ft_strncpy(char *dest, const char *src, size_t len);
int				ft_space_flag(char *str, int minus, int plus);
int				get_len(char *str, char c);
char			*ft_strpbrk(char *str, char *exist);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_precision(char *str);
int				ft_width(char *str);
int				deal_conversions(va_list *av, char **str, t_flags flags);
int				print_negwidth(t_flags flags, int ret);
int				ft_sort_types(va_list *av, t_flags flags);
t_flags			ini_flags(char *str, int ret);

int				ft_print_hex(int ret, va_list *av, t_flags flags);
int				ft_print_dec(int ret, va_list *av, t_flags flags);
int				ft_print_unsig(int ret, va_list *av, t_flags flags);
int				ft_print_oct(int ret, va_list *av, t_flags flags);
int				ft_print_lld(int ret, t_flags flags, long long val);
static void		ft_put_lld(long long nbr);
int				ft_print_space(int val, t_flags flags);
int				ft_print_plus(t_flags flags, int val);
int				ft_print_zero(int val, t_flags flags);
int				print_width_neg(t_flags flags, int ret);
void			ft_putstr(char const *s);
int				ft_print_hash(int val, t_flags flags);
int				hash_len(int val, t_flags flags);
int				ft_print_width(int ret, t_flags flags);
int				print_precision(t_flags flags, int nb, int nb_len);
void			ft_print_u_hex(unsigned long long int nb, const char *str);
int				ft_print_xll(int ret, unsigned long long val, t_flags flags);
int				ft_print_ull(int ret, t_flags flags, unsigned long long val);
size_t			ft_llu_len(unsigned long long nb);
int				ft_hex_len(unsigned long long int nb);
void			ft_put_llu_base(unsigned long long nb, char base);
static void		ft_put_lld(long long nbr);

void			ft_put_llbase(long long nbr, char base);
int				ft_print_oll(int ret, t_flags flags, long long val);
size_t			ft_len_base(long long int nb, char base);
size_t			ft_lenll(long long int nbr);
int				ft_hex_len(unsigned long long int nb);
size_t			ft_u_len_base(unsigned long long int nb, char base);
void			ft_put_longlong_base(long long nbr, char base);
int				print_u_o_longlong(int ret, t_flags flags,\
				unsigned long long nb);

void			ft_put_u_longlong_base(unsigned long long nb, char base);
int				ft_print_ou(int ret, t_flags flags, va_list *av);
int				deal_conversions(va_list *av, char **str, t_flags flags);
void			ft_print_ptr(size_t nb);
size_t			ft_ptr_len_base(size_t ptr, unsigned int base);
int				print_ptr(int ret, va_list *av, t_flags flags);
int				print_string(int ret, t_flags flags, char *str);
int				print_plain_char(int ret, t_flags flags);
void			ft_putnstr(const char *str, size_t n);
int				print_char(int ret, t_flags flags, char c);
int				ft_deal_chrstr(va_list *va, t_flags flags);
int				print_nrmchr(int ret, t_flags flags);

int				print_unicode_char(int ret, t_flags flags, wchar_t c);
int				print_unicode_string(int ret, t_flags flags, wchar_t *s);
int				ft_deal_unicodes(va_list *va, t_flags flags);
int				ft_wcharlen(wchar_t c);
int				ft_wstrlen(wchar_t *str);
int				ft_wstrnlen(wchar_t *str, int n);
void			ft_putnwstr(wchar_t *str, int len);
void			ft_putwstr(wchar_t *str);
static char		**encode(char *bin, char *m);
static char		**get_bytes(wchar_t c);
int				ft_putwchar(wchar_t c);

static int		nbr_inbase(char c, int base);
int				ft_atoi_base(const char *str, int base);
const char		*ft_skip_whitespace(const char *str);
char			**ft_strsplit(char const *s, char c);
char			*ft_strcpy(char *dest, const char *src);
void			ft_memdel(void **ap);
char			*ft_strdup(const char *src);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_itoa_longlong_base(long long n, char base);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
void			*ft_memset(void *b, int c, size_t len);
#endif
