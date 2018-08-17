/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lld.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:25:33 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 16:21:42 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_lld(int ret, t_flags flags, long long val)
{
	int len;

	len = ft_lenll(val);
	if (flags.post && val >= 0)
		ret += 1;
	ret += ft_print_space(val, flags);
	if (!(flags.prec == -9999 && val == 0))
		ret += len;
	if (flags.prec > 0 && flags.prec > len && val >= 0)
		ret += flags.prec - len;
	if (flags.prec > 0 && flags.prec == len && val < 0)
		ret += flags.prec - len + 1;
	if (flags.prec > 0 && flags.prec > len && val < 0)
		ret += flags.prec - len + 1;
	ret += ft_print_width(ret, flags);
	ft_print_plus(flags, val);
	if (val < 0)
		ft_putchar('-');
	ret += ft_print_zero(ret, flags);
	print_precision(flags, val, len);
	if (!(flags.prec == -9999 && val == 0))
		ft_put_lld(val);
	ret += print_negwidth(flags, ret);
	return (ret);
}

static void	ft_put_lld(long long nbr)
{
	unsigned long long nb;

	if (nbr < 0)
	{
		if (nbr != LONG_LONG_MIN)
			nbr *= -1;
	}
	nb = nbr;
	if (nb >= (unsigned long long)10)
		ft_put_lld(nb / 10);
	ft_putchar(nb % 10 + '0');
}
