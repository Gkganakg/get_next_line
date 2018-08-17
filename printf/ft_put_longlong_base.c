/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_longlong_base.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 12:53:53 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/12 13:05:46 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_longlong_base(long long nbr, char base)
{
	unsigned long long nb;

	if (base > 1 && base <= 10)
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			if (nbr != LONG_LONG_MIN)
				nbr *= -1;
		}
		nb = nbr;
		if (nb >= (unsigned long long)base)
			ft_put_longlong_base(nb / base, base);
		ft_putchar(nb % base + '0');
	}
	else if (base == 1)
		ft_putnchar('1', nbr);
}
