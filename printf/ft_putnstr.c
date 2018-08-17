/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:48:29 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/15 09:10:17 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(const char *str, size_t n)
{
	size_t		len;

	if (str != NULL)
	{
		len = ft_strlen(str);
		write(1, str, MIN(len, n));
	}
}
