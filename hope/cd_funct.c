/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_funct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 08:00:52 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/15 15:27:25 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	homeless(char *str1, char **str)
{
	char	*car;
	int		rett;
	int		i;
	char	*gig;

	gig = NULL;
	i = search_str(g_env, "HOME");
	car = capture_str(g_env[i]);
	car == '\0' ? exit(0) : 0;
	chdir(str[1]);
	free(car);
	rett = search_str(g_env, "PWD");
	if (rett != -1)
		saver2(str1, rett);
	return ;
}

void	home(char *str1, char **str)
{
	char	*car;
	int		rett;
	int		i;
	char	*gig;

	gig = NULL;
	i = search_str(g_env, "HOME");
	car = capture_str(g_env[i]);
	car == '\0' ? exit(0) : 0;
	if (ft_strlen(str[1]) > 1)
		car = new_envir2(car, str);
	if (access(car, F_OK) == 0)
		chdir(car);
	else
		ft_putendl("cd : No scuh file or directory");
	free(car);
	rett = search_str(g_env, "PWD");
	if (rett != -1)
		saver2(str1, rett);
	return ;
}

void	home_dir(char *str)
{
	int		ret;
	int		old;
	char	*car;
	char	*temp;
	char	*gig;

	car = NULL;
	temp = capture_str(g_env[search_str(g_env, "HOME")]);
	temp == '\0' ? exit(0) : 0;
	chdir(temp);
	ret = search_str(g_env, "PWD");
	if (ret != -1)
	{
		old = search_str(g_env, "OLDPWD");
		car = capture_str(g_env[ret]);
		gig = getcwd(str, 2048);
		free(g_env[old]);
		g_env[old] = ft_strjoin("OLDPWD=", car);
		free(g_env[ret]);
		g_env[ret] = ft_strjoin("PWD=", gig);
		free(gig);
	}
	free(temp);
	free(car);
	return ;
}

int		cd_funct(char **str)
{
	t_struct	lin;
	int			i;
	char		*back;

	back = NULL;
	i = search_str(g_env, "OLPWD");
	lin.store1 = NULL;
	lin.rett = search_str(g_env, "PWD");
	lin.store2 = ft_strchr2(g_env[lin.rett], '=');
	if (!str[1])
		home_dir(lin.store1);
	else if (lin.rett == -1)
		set_pwd(lin.store1, str);
	else if (ft_strncmp(str[1], "~", 1) == 0)
		home(lin.store1, str);
	else if ((ft_strncmp(str[1], "/", 1) == 0) && access(str[1], F_OK) == 0)
		homeless(lin.store1, str);
	else if (ft_strncmp(str[1], "-", 1) == 0)
		cd_dash();
	else if (str[1] && access(str[1], F_OK) == 0)
		saver(str, lin);
	else if (access(str[1], F_OK) == -1)
		ft_putendl("cd : No scuh file or directory");
	return (1);
}
