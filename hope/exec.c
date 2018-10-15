/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 12:29:58 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/15 17:26:12 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_path(char *buf, char *tab)
{
	char	*tmp;
	char	*tmp2;

	tmp2 = ft_strjoin(tab, "/");
	tmp = ft_strjoin(tmp2, buf);
	free(tmp2);
	return (tmp);
}

char	**chck_path(char **str)
{
	char	**tmp;
	char	*temp;

	if (search_str(str, "PATH") == -1)
		return (str);
	else
	{
		temp = ft_strchr2(str[search_str(str, "PATH")], '=');
		tmp = ft_strsplit(temp, ':');
	}
	return (tmp);
}

int		is_bultin(char **str)
{
	if (ft_strequ(str[0], "echo"))
		return (1);
	if (ft_strequ(str[0], "setenv"))
		return (1);
	if (ft_strequ(str[0], "unsetenv"))
		return (1);
	if (ft_strequ(str[0], "cd"))
		return (1);
	if (ft_strequ(str[0], "env"))
		return (1);
	return (-1);
}

void	body(t_struct lin, char **env, char **str)
{
	while (lin.hldr[lin.ind])
	{
		lin.store1 = find_path(str[0], lin.hldr[lin.ind]);
		execve(lin.store1, str, env);
		lin.ind++;
	}
	stupid(str[0]);
	exit(1);
}

void	exec(char **str, char **env)
{
	t_struct	lin;

	lin.ind = 0;
	lin.hldr = chck_path(env);
	lin.pid = fork();
	if (lin.pid != 0)
		wait(&lin.cnt);
	if (lin.pid == 0)
	{
		ft_putendl("In child");
		execve(str[0], str, env);
		if (is_bultin(str) < 0)
		{
			ex(str[0], search_str(env, "PATH"));
			ret(search_str(env, "PATH"));
			body(lin, env, str);
		}
	}
	ft_putendl("In parent");
	if (search_str(env, "PATH") == -1)
		return ;
	if (lin.hldr != NULL)
		free_2d(lin.hldr);
}
