/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:21:00 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/15 17:23:26 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	stupid(char *str)
{
	ft_putstr(str);
	ft_putendl(": command not found");
}

void	ex(char *str, int i)
{
	if (i == -1)
	{
		stupid(str);
		exit(0);
	}
}

void	ret(int i)
{
	if (i == -1)
		return ;
}
