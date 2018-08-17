/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:16:21 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/15 09:13:52 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_llx(int ret, unsigned long long val, t_flags flags)
{
	int	precision;

	prec = 0;
	ret += hash_len(val, flags);
	if (!(flags.prec == -999 && val == 0))
		ret += ft_hex_len(val);
	if (flags.prec > 0)
		precision = flags.prec - ft_hex_len(val);
	ret += ft_print_width(ret + (precision > 0 ? precision : 0), flags);
	ft_print_hash(val, flags);
	ret += ft_print_zero(ret, flags);
	ret += print_precision(format, val, ft_hex_len(val));
	if (!(flags.prec == -9999 && val == 0))
	{
		if (flags.conversion == 'x')
			ft_print_u_hex(val, "0123456789abcdef");
		else if (flags.conversion == 'X')
			ft_print_u_hex(val, "0123456789ABCDEF");
	}
	ret += print_negwidth(flags, ret);
	return (ret);
}
