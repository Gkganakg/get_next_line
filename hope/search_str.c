/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 08:08:17 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/15 12:47:15 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		clear(void)
{
	write(1, "\33[H\33[2J", 7);
	return (1);
}

char	*capture_str(char *str)
{
	int		i;
	char	*s;

	s = NULL;
	i = 0;
	while (str[i] != '=')
		i++;
	i++;
	s = ft_strdup(str + i);
	return (s);
}

int		search_str(char **env, char *key)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] != '=')
			j++;
		s = ft_strnew(j);
		s = ft_strncpy(s, env[i], j);
		if (ft_strequ(s, key))
		{
			free(s);
			return (i);
		}
		free(s);
		i++;
	}
	return (-1);
}
