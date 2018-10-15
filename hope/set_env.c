/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:03:39 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/15 11:54:44 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**add_row(char *keyval)
{
	int		i;
	int		len;
	char	**dup;

	i = 0;
	len = env_len(g_env) + 1;
	dup = (char**)malloc(sizeof(char*) * len + 1);
	if (dup == NULL)
		return (NULL);
	while (i < len - 1)
	{
		dup[i] = g_env[i];
		i++;
	}
	dup[i] = ft_strdup(keyval);
	dup[i + 1] = NULL;
	return (dup);
}

int		add_new_env(char *key, char *value)
{
	char	*tmp;
	char	*t2;

	tmp = ft_strcat(key, "=");
	t2 = ft_strcat(tmp, value);
	g_env = add_row(t2);
	return (1);
}

int		update_env(char *key, char *value, int ind)
{
	char	*cat;

	free(g_env[ind]);
	cat = ft_strcat(key, "=");
	cat = ft_strcat(cat, value);
	g_env[ind] = ft_strdup(cat);
	return (1);
}

int		manage_env(char *key, char *value)
{
	int		i;
	int		j;
	char	*s;

	i = -1;
	while (g_env[++i])
	{
		j = 0;
		while (g_env[i][j] != '=')
			j++;
		s = ft_strnew(j);
		s = ft_strncpy(s, g_env[i], j);
		if (ft_strequ(s, key))
		{
			free(s);
			return (update_env(key, value, i));
		}
		else if (i == (env_len(g_env) - 1))
		{
			free(s);
			return (add_new_env(key, value));
		}
		free(s);
	}
	return (1);
}

int		set_env(char **str)
{
	if (!str[1])
	{
		ft_putendl("Env: Too few arguments");
		return (1);
	}
	else if (str[1] && str[2] && !str[3])
		return (manage_env(str[1], str[2]));
	else if (str[1] && !str[2])
		return (manage_env(str[1], ""));
	else if (str[3])
	{
		ft_putendl("Env: Too many arguments");
		return (1);
	}
	return (0);
}
