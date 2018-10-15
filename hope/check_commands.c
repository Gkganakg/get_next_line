/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:01:22 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/15 15:33:30 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_2(char *str)
{
	char	*s;
	int		j;
	int		i;
	char	*temp;

	i = 0;
	s = NULL;
	str++;
	while (g_env[i])
	{
		j = 0;
		while (g_env[i][j] != '=')
			j++;
		s = ft_strnew(j);
		s = ft_strncpy(s, g_env[i], j);
		if (ft_strequ(s, str))
			break ;
		temp = s;
		ft_strdel(&s);
		free(s);
		i++;
	}
	if (ft_strequ(temp, str) == 1)
		ft_putstr(g_env[i] + j + 1);
	free(s);
}

void	ft_echo(char *str)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (str[i] == '$')
		echo_2(str);
	else
	{
		while (str[k])
		{
			if (str[k] != '\"' && str[k] != '\'')
				write(1, &str[k], 1);
			k++;
		}
	}
	ft_putchar(' ');
}

int		print_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
	return (1);
}

int		ft_exit(void)
{
	exit(1);
	return (1);
}

int		chck_commands(char **str)
{
	int i;

	i = 0;
	if (ft_strcmp(str[0], "setenv") == 0)
		return (set_env(str));
	else if (ft_strcmp(str[0], "unsetenv") == 0)
		return (chck_env(str));
	if (ft_strcmp(str[0], "env") == 0)
		return (print_env(g_env));
	if (ft_strcmp(str[0], "echo") == 0)
	{
		while (str[++i])
			ft_echo(str[i]);
		ft_putchar('\n');
		return (1);
	}
	else if (ft_strcmp(str[0], "cd") == 0)
		return (cd_funct(str));
	else if (ft_strcmp(str[0], "exit") == 0)
		return (ft_exit());
	else if (ft_strcmp(str[0], "clear") == 0)
		return (clear());
	else
		 exec(str, g_env);
	return (1);
}
