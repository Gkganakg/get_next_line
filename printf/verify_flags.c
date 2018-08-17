/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:10:41 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/15 09:11:42 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_post_flag(char *str)
{
	int ret;

	ret = 0;
	while (str[ret])
	{
		if (str[ret] == '+')
			return (1);
		ret++;
	}
	return (0);
}

int		ft_neg_flag(char *str)
{
	int ret;

	ret = 0;
	while (str[ret])
	{
		if (str[ret] == '-')
			return (1);
		ret++;
	}
	return (0);
}

int		ft_hash_flag(char *str)
{
	int ret;

	ret = 0;
	while (str[ret])
	{
		if (str[ret] == '#')
			return (1);
		ret++;
	}
	return (0);
}

int		ft_flag_zero(char *str, int neg)
{
	int		ret;
	char	*tmp;

	ret = 0;
	while (str[ret])
	{
		if (str[ret] == '0' && !neg)
		{
			tmp = ft_strndup(str, ret);
			if (ft_strpbrk(tmp, "123456789") == NULL \
					&& !ft_strchr(tmp, '.'))
			{
				ft_strdel(&tmp);
				return (1);
			}
			else
			{
				ft_strdel(&tmp);
				return (0);
			}
		}
		ret++;
	}
	return (0);
}

int		ft_space_flag(char *str, int post, int neg)
{
	int		ret;

	ret = 0;
	while (str[ret])
	{
		if (!neg && !post && str[ret] == ' ')
			return (1);
		ret++;
	}
	return (0);
}
