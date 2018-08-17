/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:51:37 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/15 09:11:23 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_wstrlen(wchar_t *str)
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
