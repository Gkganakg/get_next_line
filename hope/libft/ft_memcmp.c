/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:18:49 by gkganakg          #+#    #+#             */
/*   Updated: 2018/06/09 14:09:15 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*src;
	char	*dst;
	size_t	i;

	if (!s1 && !s2)
		return (0);
	src = (char*)s1;
	dst = (char*)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (src[i] != dst[i])
			return ((unsigned char)src[i] - (unsigned char)dst[i]);
		i++;
	}
	return (0);
}
