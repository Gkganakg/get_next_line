/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:28:18 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 14:57:12 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_str(va_list *av, char *str)
{
	int		val;
	int		i;

	i = 0;
	val = 0;
	while (*str != '\0')
	{
		if (*str == '%')
			val += check_flags(av, &str);
		else if (val != -1)
		{
			ft_putchar(*str);
			val++;
		}
		if (*str != '\0')
			str++;
	}
	return (val);
}

int			check_flags(va_list *av, char **tmp)
{
	int		val;
	t_flags	flags;

	val = 0;
	if ((*tmp)[val] == '%')
	{
		val++;
		if ((*tmp)[val] != '\0')
		{
			*tmp = deal_flags(&(*tmp)[val], &flags);
			return (deal_conversions(av, &(*tmp), flags));
		}
	}
	return (val);
}

char		*deal_flags(char *str, t_flags *flags)
{
	int		ret;
	char	*tmp;

	ret = 0;
	while (str[ret] && ft_strchr("#0-+ hljz.123456789", str[ret]))
	{
		ret++;
	}
	*flags = ini_flags(str, ret);
	return (&str[ret]);
}

t_flags		ini_flags(char *str, int ret)
{
	t_flags flags;
	char	*tmp;

	tmp = ft_strnew(ret);
	tmp = ft_strncpy(tmp, str, ret);
	flags.width = ft_width(tmp);
	flags.post = ft_post_flag(tmp);
	flags.neg = ft_neg_flag(tmp);
	flags.prec = ft_precision(tmp);
	flags.zero = ft_flag_zero(tmp, flags.neg);
	flags.hash = ft_hash_flag(tmp);
	flags.space = ft_space_flag(tmp, flags.post, flags.neg);
	flags.l = get_len(tmp, 'l');
	flags.h = get_len(tmp, 'h');
	flags.j = get_len(tmp, 'j');
	flags.z = get_len(tmp, 'z');
	ft_strdel(&tmp);
	return (flags);
}

int			get_len(char *str, char c)
{
	int ret;
	int val;

	ret = 0;
	val = 0;
	while (str[val])
	{
		if (str[val] == c)
			ret++;
		val++;
	}
	return (ret);
}
