/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_len_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 11:58:28 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/11 13:11:33 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_u_len_base(unsigned long long int nb, char base)
{
	size_t len;

	len = 1;
	while (nb >= (unsigned long long)base)
	{
		nb = nb / base;
		len++;
	}
	return (len);
}
