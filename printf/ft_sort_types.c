/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 09:43:50 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 16:42:02 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sort_types(va_list *av, t_flags flags)
{
	int		ret;
	char	type;

	ret = 0;
	type = flags.conversion;
	if (type == 'd' || type == 'i' || type == 'D')
		ret += ft_print_dec(ret, av, flags);
	else if (type == 'x' || type == 'X')
		ret += ft_print_hex(ret, av, flags);
	else if (type == 'u' || type == 'U')
		ret += ft_print_unsig(ret, av, flags);
	else if (type == 'o' || type == 'O')
		ret += ft_print_oct(ret, av, flags);
	return (ret);
}

int		ft_print_dec(int ret, va_list *av, t_flags flags)
{
	char		type;
	long long	val;

	type = flags.conversion;
	val = 0;
	if (type == 'i' || type == 'd' || type == 'D')
	{
		if (flags.l == 1 || type == 'D')
			val = (long long)va_arg(*av, long);
		else if (flags.l == 2)
			val = (long long)va_arg(*av, long long);
		else if (flags.z == 1)
			val = (size_t)va_arg(*av, size_t);
		else if (flags.h == 1)
			val = (short)va_arg(*av, int);
		else if (flags.h == 2)
			val = (char)va_arg(*av, int);
		else if (flags.j == 1)
			val = (intmax_t)va_arg(*av, intmax_t);
		else
			val = (long long)va_arg(*av, int);
		ret += ft_print_lld(ret, flags, val);
	}
	return (ret);
}

int		ft_print_hex(int ret, va_list *av, t_flags flags)
{
	char				type;
	unsigned long long	val;

	type = flags.conversion;
	if (flags.z == 1)
		val = (size_t)va_arg(*av, size_t);
	else if (flags.h == 1)
		val = (unsigned short)va_arg(*av, unsigned int);
	else if (flags.h == 2)
		val = (unsigned char)va_arg(*av, unsigned int);
	else if (flags.l == 1)
		val = (unsigned long long)va_arg(*av, unsigned long);
	else if (flags.l == 2)
		val = (unsigned long long)va_arg(*av, unsigned long long);
	else if (flags.j == 1)
		val = (uintmax_t)va_arg(*av, uintmax_t);
	else
		val = (unsigned long long)va_arg(*av, unsigned int);
	ret += ft_print_xll(ret, val, flags);
	return (ret);
}

int		ft_print_unsig(int ret, va_list *av, t_flags flags)
{
	char				type;
	unsigned long long	val;

	type = flags.conversion;
	if (type == 'u' || type == 'U')
	{
		if (flags.z == 1)
			val = (size_t)va_arg(*av, size_t);
		else if (flags.j == 1)
			val = (uintmax_t)va_arg(*av, uintmax_t);
		else if (flags.l == 1 || type == 'U')
			val = (unsigned long long)va_arg(*av, unsigned long);
		else if (flags.l == 2)
			val = (unsigned long long)va_arg(*av, unsigned long long);
		else if (flags.h == 1)
			val = (unsigned short)va_arg(*av, unsigned int);
		else if (flags.h == 2)
			val = (unsigned char)va_arg(*av, unsigned int);
		else
			val = (unsigned long long)va_arg(*av, unsigned int);
		ret += ft_print_ull(ret, flags, val);
	}
	return (ret);
}

int		ft_print_oct(int ret, va_list *av, t_flags flags)
{
	long long val;

	if (flags.l || flags.h || flags.j || flags.z || flags.conversion == 'O')
		ret += ft_print_ou(ret, flags, av);
	else
	{
		val = (long long)va_arg(*av, unsigned int);
		ret += ft_print_oll(ret, flags, val);
	}
	return (ret);
}
