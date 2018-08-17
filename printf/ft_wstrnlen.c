/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:52:03 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 16:52:22 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_wstrnlen(wchar_t *str, int n)
{
	int	i;
	int	len;

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
