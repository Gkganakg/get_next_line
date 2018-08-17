/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:19:05 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/09 14:38:59 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*b;
	int		i;

	b = (char *)malloc((sizeof(char) * size + 1));
	i = 0;
	if (!b)
		return (NULL);
	ft_bzero(b, size + 1);
	return (b);
}
