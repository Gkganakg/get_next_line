/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 13:56:48 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/15 14:02:16 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			exec_cmd(char **cmd, char **env)
{
	pid_t	process;
	char	*bin;

	bin = chaeck_path(g_env);
	if (bin == NULL)
	{
		stupid(cmd[0]);
		return (1);
	}
	process = fork();
	if (process == 0)
		process = execve(bin, cmd, env);
	else
		wait(&process);
	ft_strdel(&bin);
	return (1);
}
