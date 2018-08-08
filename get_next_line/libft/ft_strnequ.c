/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:06:10 by gkganakg          #+#    #+#             */
/*   Updated: 2018/05/29 17:22:26 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	i = 0;
	if (n)
	{
		while (i < n)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
	}
	return (1);
}
