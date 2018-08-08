/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 12:46:49 by gkganakg          #+#    #+#             */
/*   Updated: 2018/06/05 12:14:16 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
