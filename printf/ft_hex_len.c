/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 14:12:40 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/15 09:12:53 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned long long int nb)
{
	int ret;

	ret = 0;
	if (nb < 16)
		ret = 1;
	else
		ret = ft_u_len_base(nb, 16);
	return (ret);
}
