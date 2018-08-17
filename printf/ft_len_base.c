/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:46:38 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 16:46:43 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_len_base(long long int nb, char base)
{
	size_t len;

	len = 1;
	if (nb < 0)
	{
		len++;
		nb = -nb;
	}
	while (nb >= base)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}
