/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:44:40 by gkganakg          #+#    #+#             */
/*   Updated: 2018/06/11 17:53:26 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t i;
	size_t k;

	i = 0;
	k = 0;
	while (s[i] != '\0')
		i++;
	while (i > 0)
	{
		if (s[i] == (char)c)
			return ((char*)&s[i]);
		i--;
	}
	if (s[i] != (char)c)
		return (NULL);
	else
		return ((char*)&s[i]);
}
