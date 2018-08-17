/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:28:18 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/15 09:14:11 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *fmt, ...)
{
	size_t	ret;
	va_list av;

	ret = 0;
	if (fmt)
	{
		va_start(av, (char*)fmt);
		ret += parse_str(&av, (char*)fmt);
		va_end(av);
	}
	return (ret);
}
