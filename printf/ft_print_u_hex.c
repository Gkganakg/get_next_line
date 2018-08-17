/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:15:16 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/13 11:50:58 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u_hex(unsigned long long int nb, const char *str)
{
	if (nb < 16)
		ft_putchar(str[nb]);
	else
	{
		ft_print_u_hex(nb / 16, str);
		ft_putchar(str[nb % 16]);
	}
}
