/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 14:04:30 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/15 11:41:12 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		del_env(char *key, char **env)
{
	int	k;
	int	len;

	k = 0;
	len = ft_strlen(key);
	while (env[k])
	{
		if ((ft_strncmp(env[k], key, len) == 0) && \
				(ft_strncmp(env[k] + len, "=", 1) == 0))
		{
			free(env[k]);
			while (env[k + 1])
			{
				env[k] = env[k + 1];
				k++;
			}
			env[k] = NULL;
			return (1);
		}
		k++;
	}
	return (1);
}

int		ft_error(char *s)
{
	ft_putstr(s);
	ft_putendl(" : invalid in env");
	return (1);
}

int		unset_env(char *str)
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
		if (ft_strequ(s, str))
		{
			free(s);
			return (del_env(str, g_env));
		}
		else if (i == ((env_len(g_env) - 1)))
		{
			free(s);
			return (ft_error(str));
		}
		free(s);
	}
	return (1);
}

int		chck_env(char **str)
{
	if (str[1] && !str[2])
	{
		unset_env(str[1]);
		return (1);
	}
	else if (str[1] && str[2])
	{
		ft_putendl("Too many arguments Baka");
		return (1);
	}
	else if (!str[1])
	{
		ft_putendl("Env not specified Baka");
		return (1);
	}
	return (1);
}
