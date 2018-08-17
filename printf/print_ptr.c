/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/11 15:31:13 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 14:47:51 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			print_ptr(int ret, va_list *av, t_flags flags)
{
	void	*ptr;
	int		p_len;
	int		precision;

	precision = 0;
	ptr = va_arg(*av, void *);
	p_len = ft_ptr_len_base((size_t)ptr, 16);
	if (!(flags.prec == -9999 && ptr == 0))
		ret += p_len;
	ret += 2;
	if (flags.prec > 0)
		precision = flags.prec - (ptr < 0 ? p_len - 1 : p_len);
	ret += ft_print_width(ret + (precision > 0 ? precision : 0), flags);
	ft_putstr("0x");
	ret += ft_print_zero(ret, flags);
	ret += print_precision(flags, (int)ptr, p_len);
	if (!(flags.prec == -9999 && ptr == 0))
		ft_print_ptr((size_t)ptr);
	ret += print_negwidth(flags, ret);
	return (ret);
}

void		ft_print_ptr(size_t nb)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(str[nb]);
	else
	{
		ft_print_ptr(nb / 16);
		ft_putchar(str[nb % 16]);
	}
}

size_t		ft_ptr_len_base(size_t ptr, unsigned int base)
{
	size_t	len;

	len = 1;
	while (ptr >= base)
	{
		ptr /= base;
		len++;
	}
	return (len);
}
