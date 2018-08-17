/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_longlong_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 12:34:38 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/12 12:35:08 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_longlong_base(long long n, char base)
{
	char	*s;
	int		i;
	char	tab[17];

	i = ft_len_base(n, base) - 1;
	ft_strcpy(tab, "0123456789abcdef");
	s = ft_strnew(ft_len_base(n, base));
	if (base < 2 || base > 16 || (base != 10 && n < 0))
		return (NULL);
	if (base == 10)
		return (ft_itoa(n));
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (i >= 0 && s[i] != '-')
	{
		s[i] = tab[n % base];
		n = n / base;
		i--;
	}
	return (s);
}
