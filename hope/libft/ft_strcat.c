/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:37:25 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/13 14:03:02 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	int i;
	int k;

	i = ft_strlen(dst);
	k = 0;
	while (src[k] != '\0')
	{
		dst[i + k] = src[k];
		k++;
	}
	dst[i + k] = '\0';
	return (dst);
}
