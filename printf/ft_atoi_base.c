/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 12:19:44 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/12 12:38:51 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbr_inbase(char c, int base)
{
	if (base <= 10)
		return (c >= '0' && c <= '9');
	return ((c >= '0' && c <= '9') || (c >= 'A' && c <= ('A' + base - 10)) ||
	(c >= 'a' && c <= ('a' + base - 10)));
}

int			ft_atoi_base(const char *str, int base)
{
	int		i;
	int		nbr;
	int		sign;

	i = 0;
	if (!str[0] || (base < 2 || base > 16))
		return (0);
	nbr = 0;
	sign = 1;
	str = ft_skip_whitespace(str);
	if (*str == '-' && str++)
		sign = -1;
	else if (*str == '+' && sign != -1)
		str++;
	while (str[i] && nbr_inbase(str[i], base))
	{
		if (str[i] >= 'A' && 'F' >= str[i])
			nbr = (nbr * base) + (str[i] - 'A' + 10);
		else if (str[i] >= 'a' && 'f' >= str[i])
			nbr = (nbr * base) + (str[i] - 'a' + 10);
		else
			nbr = (nbr * base) + (str[i] - '0');
		i += 1;
	}
	return (nbr * sign);
}
