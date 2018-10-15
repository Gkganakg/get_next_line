/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 10:43:23 by gkganakg          #+#    #+#             */
/*   Updated: 2018/06/13 11:59:22 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*csrc;
	unsigned char		*cdst;

	i = 0;
	csrc = (unsigned char*)src;
	cdst = (unsigned char*)dst;
	if (cdst > csrc)
	{
		while ((int)len--)
		{
			cdst[len] = csrc[len];
		}
	}
	else
		while (i < len)
		{
			cdst[i] = csrc[i];
			i++;
		}
	return (cdst);
}
