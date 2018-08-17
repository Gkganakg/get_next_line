/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_unicodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 16:39:40 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/12 11:44:28 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_deal_unicodes(va_list *va, t_flags flags)
{
	int		ret;
	wchar_t	c;
	wchar_t	*s;

	ret = 0;
	if (flags.conversion == 'C' || flags.conversion == 'c')
	{
		c = (wchar_t)va_arg(*va, wint_t);
		ret += print_unicode_char(ret, flags, c);
	}
	else if (flags.conversion == 'S' || flags.conversion == 's')
	{
		s = (wchar_t *)va_arg(*va, wchar_t *);
		ret += print_unicode_string(ret, flags, s);
	}
	return (ret);
}

int		print_unicode_char(int ret, t_flags flags, wchar_t c)
{
	int	precision;

	precision = flags.prec;
	if (c == 0)
	{
		ft_putchar('\0');
		ret += 0;
	}
	if ((c >= 55296 && c < 57344) || c < 0)
		return (-1);
	ret += ft_wcharlen(c);
	ret += ft_print_width(ret, flags);
	ret += ft_print_zero(ret, flags);
	ft_putwchar(c);
	ret += print_negwidth(flags, ret);
	return (ret);
}

int		print_unicode_string(int ret, t_flags flags, wchar_t *s)
{
	int		precision;
	int		len;

	precision = flags.prec;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	len = ft_wstrlen(s);
	if (precision == 0)
		ret += len;
	else if (precision > 0)
		ret += ft_wstrnlen(s, precision);
	ret += ft_print_width(ret, flags);
	ret += ft_print_zero(ret, flags);
	if (precision > 0)
		ft_putnwstr(s, ft_wstrnlen(s, precision));
	else if (precision != -1)
		ft_putwstr(s);
	ret += print_negwidth(flags, ret);
	return (ret);
}
