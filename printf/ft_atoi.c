/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 11:20:21 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/09 15:27:49 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n') ||
		(str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] != '\0') && (str[i] >= '0') && (str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}
