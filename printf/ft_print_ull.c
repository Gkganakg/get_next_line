/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_llu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 09:40:58 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/13 17:03:05 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ull(int ret, t_flags flags, unsigned long long val)
{
	int	precision;
	int	len;

	precision = flags.prec;
	len = ft_llu_len(val);
	ret += ft_print_plus(flags, val);
	ret += ft_print_space(val, flags);
	if (!(precision == -9999 && val == 0))
		ret += len;
	if (precision > 0 && precision > len)
		ret += precision - len;
	ret += ft_print_width(ret, flags);
	ret += ft_print_zero(ret, flags);
	print_precision(flags, val, len);
	if (!(precision == -9999 && val == 0))
		ft_put_llu_base(val, 10);
	ret += print_negwidth(flags, ret);
	return (ret);
}
