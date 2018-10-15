/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:19:05 by gkganakg          #+#    #+#             */
/*   Updated: 2018/06/14 12:26:43 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*b;
	int		i;

	b = (char *)malloc((sizeof(char) * size + 1));
	i = 0;
	if (!b)
		return (NULL);
	ft_bzero(b, size + 1);
	return (b);
}
