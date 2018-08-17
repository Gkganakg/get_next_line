/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 10:00:11 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 15:54:06 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_oll(int ret, t_flags flags, long long val)
{
	int precision;
	int len;

	precision = 0;
	len = ft_len_base(val, 8);
	if (flags.prec != -9999 || val != 0 || flags.hash)
		ret += len;
	if (flags.prec > 0)
		precision = flags.prec - (val < 0 ? len - 1 : len);
	if (flags.hash && val != 0)
	{
		flags.prec -= 1;
		ret += 1;
	}
	ret += ft_print_width(ret + (precision > 0 ? precision : 0), flags);
	ft_print_hash(val, flags);
	ret += ft_print_zero(ret, flags);
	ret += print_precision(flags, val, len);
	if (flags.prec != -9999 || val != 0)
		ft_put_longlong_base(val, 8);
	ret += print_negwidth(flags, ret);
	return (ret);
}

int		ft_print_ou(int ret, t_flags flags, va_list *av)
{
	unsigned long long	nb;

	nb = 0;
	if (flags.l == 1 || flags.conversion == 'O')
		nb = (unsigned long long)va_arg(*av, unsigned long);
	else if (flags.l == 2)
		nb = (unsigned long long)va_arg(*av, unsigned long long);
	else if (flags.h == 1)
		nb = (unsigned short)va_arg(*av, unsigned int);
	else if (flags.h == 2)
		nb = (unsigned char)va_arg(*av, unsigned int);
	else if (flags.j == 1)
		nb = (uintmax_t)va_arg(*av, uintmax_t);
	else if (flags.z == 1)
		nb = (size_t)va_arg(*av, size_t);
	ret += print_u_o_longlong(ret, flags, nb);
	return (ret);
}

int		print_o_longlong(int ret, t_flags flags, long long nb)
{
	int precision;
	int nb_len;

	precision = 0;
	nb_len = ft_len_base(nb, 8);
	if (flags.prec != -1 || nb != 0 || flags.hash)
		ret += nb_len;
	if (flags.prec > 0)
		precision = flags.prec - (nb < 0 ? nb_len - 1 : nb_len);
	if (flags.hash && nb != 0)
	{
		flags.prec -= 1;
		ret += 1;
	}
	ret += ft_print_width(ret + (precision > 0 ? precision : 0), flags);
	ft_print_hash(nb, flags);
	ret += ft_print_zero(ret, flags);
	ret += print_precision(flags, nb, nb_len);
	if (flags.prec != -1 || nb != 0)
		ft_put_longlong_base(nb, 8);
	ret += print_negwidth(flags, ret);
	return (ret);
}

int		print_u_o_longlong(int ret, t_flags flags, unsigned long long nb)
{
	int precision;
	int nb_len;

	precision = 0;
	nb_len = ft_u_len_base(nb, 8);
	if (!(flags.prec == -1 && nb == 0))
		ret += nb_len;
	ret += ft_print_hash(nb, flags);
	if (flags.prec > 0)
		precision = flags.prec - nb_len;
	ret += ft_print_width(ret + (precision > 0 ? precision : 0), flags);
	ret += ft_print_zero(ret, flags);
	ret += print_precision(flags, nb, nb_len);
	if (!(flags.prec == -9999 && nb == 0))
		ft_put_u_longlong_base(nb, 8);
	ret += print_negwidth(flags, ret);
	return (ret);
}
