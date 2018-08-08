/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 13:51:33 by gkganakg          #+#    #+#             */
/*   Updated: 2018/06/14 12:31:33 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cdst;
	char	*csrc;
	size_t	i;

	i = 0;
	cdst = (char*)dst;
	csrc = (char*)src;
	while (i < n)
	{
		cdst[i] = csrc[i];
		i++;
	}
	return (dst);
}
