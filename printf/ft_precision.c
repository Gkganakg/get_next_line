/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:46:49 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/13 15:45:53 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision(char *str)
{
	int		ind;
	int		val;
	char	hld[ft_strlen(str)];

	ind = 0;
	val = 0;
	ft_memset(hld, '\0', ft_strlen(str));
	while (str[ind])
	{
		if (str[ind] == '.')
		{
			ft_memset(hld, '\0', ft_strlen(str));
			val = 0;
			ind++;
			while (ft_strchr("0123456789", str[ind]) && str[ind])
				hld[val++] = str[ind++];
		}
		else
			ind++;
	}
	if (ft_strchr(str, '.') && (ft_strcmp(hld, "0") == 0 || hld[0] == '\0'))
		return (-9999);
	return (ft_atoi(hld));
}
