/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 13:35:51 by gkganakg          #+#    #+#             */
/*   Updated: 2018/06/07 13:46:09 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * n + 1);
	if (tmp == NULL)
		return (NULL);
	tmp = ft_strncpy(tmp, s, n);
	tmp[n] = '\0';
	return (tmp);
}
