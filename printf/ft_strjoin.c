/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 10:40:00 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/12 12:43:39 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*b;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	b = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!b)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		b[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		b[i + j] = s2[j];
		j++;
	}
	b[i + j] = '\0';
	return (b);
}
