/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 16:08:19 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/13 16:05:31 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width(char *str)
{
	int		ind;
	int		val;
	int		width;
	char	*hld;
	char	*tmp;

	ind = 0;
	val = 0;
	width = 0;
	hld = ft_strnew(ft_strlen(str));
	while (str[ind])
	{
		tmp = ft_strndup(str, ind);
		if (ft_strchr("0123456789", str[ind]) && !ft_strchr(tmp, '.'))
		{
			hld[val] = str[ind];
			val++;
		}
		ft_strdel(&tmp);
		ind++;
	}
	width = ft_atoi(hld);
	ft_strdel(&hld);
	return (width);
}
