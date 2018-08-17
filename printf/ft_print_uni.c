/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/12 11:51:06 by gkganakg          #+#    #+#             */
/*   Updated: 2018/08/14 16:10:15 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_putnwstr(wchar_t *str, int len)
{
	int i;

	i = 0;
	while (len > 0 && str[i] != '\0')
	{
		if (ft_wcharlen(str[i]) > len)
			break ;
		else
			ft_putwchar(str[i]);
		i++;
		len -= ft_wcharlen(str[i]);
	}
}

void			ft_putwstr(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putwchar(str[i]);
		i++;
	}
}

static char		**encode(char *bin, char *m)
{
	int		j;
	int		i;
	char	*mask;
	char	**split;

	if (!(mask = ft_strdup(m)))
		return (NULL);
	i = ft_strlen(mask) - 1;
	j = ft_strlen(bin) - 1;
	while (i >= 0 && j >= 0)
	{
		if (mask[i] == 'x')
			mask[i] = bin[j--];
		i--;
	}
	i = 0;
	while (i < (int)ft_strlen(mask))
	{
		if (mask[i] == 'x')
			mask[i] = '0';
		i++;
	}
	split = ft_strsplit(mask, ' ');
	free(mask);
	return (split);
}

static char		**get_bytes(wchar_t c)
{
	char	*bin;
	char	**bytes;

	bin = ft_itoa_longlong_base((int)c, 2);
	if ((c <= 127 && MB_CUR_MAX >= 1) || (c <= 255 && MB_CUR_MAX == 1))
		bytes = encode(bin, "0xxxxxxx");
	else if (c <= 2047 && MB_CUR_MAX >= 2)
		bytes = encode(bin, "110xxxxx 10xxxxxx");
	else if (c <= 65535 && MB_CUR_MAX >= 3)
		bytes = encode(bin, "1110xxxx 10xxxxxx 10xxxxxx");
	else if (c <= 1114111 && MB_CUR_MAX >= 4)
		bytes = encode(bin, "11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	else
		bytes = NULL;
	ft_memdel((void **)&bin);
	return (bytes);
}

int				ft_putwchar(wchar_t c)
{
	char	**bytes;
	int		i;

	i = 0;
	if (!(bytes = get_bytes(c)))
		return (-1);
	while (bytes[i])
	{
		ft_putchar(ft_atoi_base(bytes[i], 2));
		ft_memdel((void **)&bytes[i]);
		i++;
	}
	ft_memdel((void **)&bytes);
	return (i);
}
