/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 12:35:50 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 15:31:12 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strpbrk(char *str, char *exist)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (exist[j])
		{
			if (str[i] == exist[j])
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
