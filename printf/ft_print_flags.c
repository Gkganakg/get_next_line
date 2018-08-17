/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 15:52:58 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 15:15:40 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_space(int val, t_flags flags)
{
	if (flags.space && ft_strchr("diD", flags.conversion))
	{
		if (val >= 0)
		{
			ft_putchar(' ');
			return (1);
		}
	}
	return (0);
}

int			ft_print_plus(t_flags flags, int val)
{
	if (flags.post && val >= 0 && !ft_strchr("uU", flags.conversion))
	{
		ft_putchar('+');
		return (1);
	}
	return (0);
}

int			ft_print_zero(int val, t_flags flags)
{
	int		zeros;
	int		ind;

	zeros = 0;
	ind = 0;
	if (flags.zero == 1 && (flags.width > val))
	{
		ind = flags.width - val;
		while (ind > 0)
		{
			ft_putchar('0');
			zeros++;
			ind--;
		}
	}
	return (zeros);
}

int			ft_print_hash(int val, t_flags flags)
{
	char	type;

	type = flags.conversion;
	if (flags.hash && ft_strchr("oO", type) && val != 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (flags.hash && ft_strchr("oO", type) && flags.prec && val == 0)
	{
		ft_putchar('0');
		return (1);
	}
	else if (flags.hash && type == 'x' && val != 0)
	{
		ft_putstr("0x");
		return (2);
	}
	else if (flags.hash && type == 'X' && val != 0)
	{
		ft_putstr("0X");
		return (2);
	}
	return (0);
}

int			hash_len(int val, t_flags flags)
{
	if (flags.hash && ft_strchr("oO", flags.conversion) && val != 0)
		return (1);
	else if (flags.hash && flags.conversion == 'x' && val != 0)
		return (2);
	else if (flags.hash && flags.conversion == 'X' && val != 0)
		return (2);
	return (0);
}
