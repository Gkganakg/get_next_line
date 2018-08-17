/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_llx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 14:24:52 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 15:30:10 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_xll(int ret, unsigned long long nb, t_flags flags)
{
	int	precision;

	precision = 0;
	ret += hash_len(nb, flags);
	if (!(flags.prec == -9999 && nb == 0))
		ret += ft_hex_len(nb);
	if (flags.prec > 0)
		precision = flags.prec - ft_hex_len(nb);
	ret += ft_print_width(ret + (precision > 0 ? precision : 0), flags);
	ft_print_hash(nb, flags);
	ret += ft_print_zero(ret, flags);
	ret += print_precision(flags, nb, ft_hex_len(nb));
	if (!(flags.prec == -9999 && nb == 0))
	{
		if (flags.conversion == 'x')
			ft_print_u_hex(nb, "0123456789abcdef");
		else if (flags.conversion == 'X')
			ft_print_u_hex(nb, "0123456789ABCDEF");
	}
	ret += print_negwidth(flags, ret);
	return (ret);
}
