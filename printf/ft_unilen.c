/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 16:47:35 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 15:21:21 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wcharlen(wchar_t c)
{
	if (c < 0 || (c >= 0xd800 && c < 0xe000))
		return (0);
	if ((c <= 127 && MB_CUR_MAX >= 1) || (c <= 255 && MB_CUR_MAX == 1))
		return (1);
	else if (c <= 2047 && MB_CUR_MAX >= 2)
		return (2);
	else if (c <= 65535 && MB_CUR_MAX >= 3)
		return (3);
	else if (c <= 1114111 && MB_CUR_MAX >= 4)
		return (4);
	return (-1);
}

int		ft_wstrlen(wchar_t *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += ft_wcharlen(str[i]);
		i++;
	}
	return (len);
}

int		ft_wstrnlen(wchar_t *str, int n)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if ((len + ft_wcharlen(str[i])) > n)
			break ;
		else
			len += ft_wcharlen(str[i]);
		i++;
	}
	return (len);
}
