/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:46:49 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/12 12:32:50 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*b;

	if (!s)
		return (NULL);
	b = (char *)malloc((sizeof(char) * len + 1));
	if (!b)
		return (NULL);
	i = 0;
	while (i < len)
	{
		b[i] = s[start + i];
		i++;
	}
	b[i] = '\0';
	return (b);
}
