/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saverr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:03:17 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/15 17:20:46 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_pwd(char *str, char **tmp)
{
	char	*pack;
	char	*temp;
	char	*mes;
	char	*here;

	if (ft_strcmp(tmp[1], "/") != 0)
	{
		here = getcwd(str, 2048);
		temp = ft_strjoin(here, "/");
		free(here);
		mes = ft_strjoin(temp, tmp[1]);
		free(temp);
		pack = ft_strjoin(mes, "/");
		free(mes);
	}
	else
		pack = ft_strdup("/");
	chdir(pack);
	free(pack);
}

void	cd_dash(void)
{
	int		i;
	char	*old;
	char	*pwd;
	int		oldi;
	char	*ci;

	ci = NULL;
	ci = getcwd(ci, 1024);
	i = search_str(g_env, "PWD");
	pwd = ft_strchr(g_env[i], '=');
	oldi = search_str(g_env, "OLDPWD");
	old = capture_str(g_env[oldi]);
	free(g_env[i]);
	g_env[i] = ft_strjoin("PWD=", old);
	free(g_env[oldi]);
	g_env[oldi] = ft_strjoin("OLDPWD=", ci);
	chdir(old);
	ft_putendl(old);
	free(old);
	free(ci);
}

void	saver2(char *str, int rett)
{
	char	*gig;
	int		len;

	gig = NULL;
	str = getcwd(str, 2048);
	gig = capture_str(g_env[rett]);
	len = search_str(g_env, "OLDPWD");
	free(g_env[len]);
	g_env[len] = ft_strjoin("OLDPWD=", gig);
	free(g_env[rett]);
	g_env[rett] = ft_strjoin("PWD=", str);
	free(gig);
	free(str);
}

char	*new_envir2(char *n, char **arg)
{
	char	*tmp;
	char	*lst;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(arg[1]) - 1));
	while (arg[1][i] == '~')
		i++;
	while (i < ft_strlen(arg[1]))
	{
		tmp[j] = arg[1][i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	lst = ft_strjoin(n, tmp);
	free(n);
	free(tmp);
	return (lst);
}

void	saver(char **str, t_struct lin)
{
	char	*back;
	int		i;

	back = NULL;
	i = search_str(g_env, "OLPWD");
	set_pwd(lin.store1, str);
	free(lin.store1);
	lin.rett = search_str(g_env, "PWD");
	free(g_env[i]);
	g_env[i] = ft_strjoin("OLDPWD", lin.store2);
	free(g_env[lin.rett]);
	back = getcwd(lin.store1, 2048);
	g_env[lin.rett] = ft_strjoin("PWD=", back);
	free(back);
}
