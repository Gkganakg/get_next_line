/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_whitespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 12:19:00 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/12 12:23:42 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_skip_whitespace(const char *str)
{
	const char	*s;

	s = str;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	return (s);
}
