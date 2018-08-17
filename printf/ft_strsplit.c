/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 16:50:57 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 16:50:59 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_word_len(char const *s, char c)
{
	unsigned int	i;
	int				len;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] && (s[i] != c))
		{
			i++;
			len++;
		}
	}
	return (len + 1);
}

char			**ft_strsplit(char const *s, char c)
{
	int				i;
	int				j;
	int				k;
	char			**str;

	i = 0;
	k = 0;
	if (s == NULL)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_word_len(s, c)) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			str[k++] = ft_strsub(s, j, i - j);
	}
	str[k] = (NULL);
	return (str);
}
