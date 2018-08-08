/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:31:03 by gkganakg          #+#    #+#             */
/*   Updated: 2018/06/11 11:31:46 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *hay, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char*)hay);
	i = 0;
	while (hay[i])
	{
		j = 0;
		while (hay[i + j] && hay[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)&hay[i]);
		}
		i++;
	}
	return (NULL);
}
