/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_llu_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 15:32:13 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 15:32:15 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_llu_base(unsigned long long nb, char base)
{
	if (base > 1 && base <= 10)
	{
		if (nb < (unsigned long long)base)
			ft_putchar('0' + nb);
		else
		{
			ft_put_u_longlong_base(nb / base, base);
			ft_putchar('0' + nb % base);
		}
	}
	else if (base == 1)
		ft_putnchar('1', nb);
}
