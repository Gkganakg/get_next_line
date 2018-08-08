/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:58:00 by nmandlan          #+#    #+#             */
/*   Updated: 2018/06/14 13:59:00 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
