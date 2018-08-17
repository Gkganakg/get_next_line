/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_conversions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:00:40 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/13 12:05:16 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		deal_conversions(va_list *av, char **str, t_flags flags)
{
	int	ret;
	int	val;

	val = 0;
	ret = 0;
	flags.conversion = (*str)[val];
	if (flags.conversion == 'p')
		ret = print_ptr(ret, av, flags);
	else if (ft_strchr("sc", flags.conversion))
		ret = ft_deal_chrstr(av, flags);
	else if (ft_strchr("dDiuUoOuUxX", flags.conversion))
		ret = ft_sort_types(av, flags);
	else if (ft_strchr("SC", flags.conversion) || \
			(ft_strchr("sc", flags.conversion) && flags.l == 1))
		ret = ft_deal_unicodes(av, flags);
	else
		ret = print_nrmchr(ret, flags);
	*str = &(*str)[val];
	return (ret);
}
