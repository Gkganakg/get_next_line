/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_chrstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 15:48:16 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/15 09:03:00 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_deal_chrstr(va_list *va, t_flags flags)
{
	int		ret;
	char	c;
	char	*str;

	ret = 0;
	if (flags.conversion == 'c')
	{
		c = (char)va_arg(*va, int);
		ret += print_char(ret, flags, c);
	}
	else if (flags.conversion == 's')
	{
		str = (char *)va_arg(*va, char *);
		ret += print_string(ret, flags, str);
	}
	return (ret);
}

int		print_char(int ret, t_flags flags, char c)
{
	ret += 1;
	ret += ft_print_width(ret, flags);
	ret += ft_print_zero(ret, flags);
	ft_putchar(c);
	ret += print_negwidth(flags, ret);
	return (ret);
}

int		print_string(int ret, t_flags flags, char *str)
{
	int		precision;

	precision = flags.prec;
	if (str || precision != 0)
	{
		if (precision == 0 && ft_strlen(str) > 0)
			ret += (int)ft_strlen(str);
		else if (str && precision > 0 && precision < (int)ft_strlen(str))
			ret += precision;
		else if (str && precision > 0)
			ret += (int)ft_strlen(str);
		ret += ft_print_width(ret, flags);
		ret += ft_print_zero(ret, flags);
		if (precision > 0)
			ft_putnstr(str, precision);
		else if (precision != -1)
			ft_putstr(str);
	}
	else
	{
		ft_putstr("(null)");
		ret += 6;
	}
	ret += print_negwidth(flags, ret);
	return (ret);
}

int		print_nrmchr(int ret, t_flags flags)
{
	ret += 1;
	ret += ft_print_width(ret, flags);
	ret += ft_print_zero(ret, flags);
	ft_putchar(flags.conversion);
	ret += print_negwidth(flags, ret);
	return (ret);
}

void	ft_putnstr(const char *str, size_t n)
{
	size_t	len;

	if (str != NULL)
	{
		len = ft_strlen(str);
		write(1, str, MIN(len, n));
	}
}
