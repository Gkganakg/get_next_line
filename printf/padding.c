/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 14:57:24 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 14:57:48 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_width(int ret, t_flags flags)
{
	int	spaces;
	int	i;

	spaces = 0;
	i = flags.width - ret;
	if (flags.width > 0 && flags.width > ret && !flags.neg)
	{
		while (i-- > 0)
		{
			if (ft_strchr("cDOUCsSp", flags.conversion)
			&& (flags.zero && (flags.neg || flags.prec)))
			{
				ft_putchar('0');
				spaces++;
			}
			else if (!flags.zero || (ft_strchr("duo", flags.conversion)
			&& flags.prec && flags.zero))
			{
				ft_putchar(' ');
				spaces++;
			}
		}
	}
	return (spaces);
}

int	print_negwidth(t_flags flags, int ret)
{
	int	spaces;
	int	i;
	int	wid;

	spaces = 0;
	wid = flags.width;
	i = 0;
	if (wid > 0 && wid > ret && !flags.zero && flags.neg)
	{
		i = wid - ret;
		while (i > 0)
		{
			ft_putchar(' ');
			spaces++;
			i--;
		}
	}
	return (spaces);
}

int	print_precision(t_flags flags, int nb, int nb_len)
{
	int	zeroes_written;
	int	i;

	zeroes_written = 0;
	i = 0;
	if (nb < 0)
		nb_len -= 1;
	if (flags.prec != -9999 && flags.prec > nb_len)
	{
		i = (flags.prec - nb_len);
		while (i > 0)
		{
			ft_putchar('0');
			zeroes_written++;
			i--;
		}
	}
	return (zeroes_written);
}
