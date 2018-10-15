/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 11:45:49 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/15 14:19:30 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define BUFF_SIZE 1024

char	**split_byspace(char *str)
{
	int		i;
	char	**split;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			str[i] = ' ';
		i++;
	}
	split = ft_strsplit(str, ' ');
	return (split);
}

int		minishel(void)
{
	char	buf[BUFF_SIZE];
	int		ret;
//	int		i;
	char	**split;

//	i = 0;
	while (1)
	{
		ft_putstr("$> ");
		ret = read(0, buf, BUFF_SIZE);
		if (ret == 0)
		{
			ft_putchar('\n');
			return (1);
		}
		buf[ret - 1] = '\0';
		split = split_byspace(buf);
		if (split[0] && g_env)
			chck_commands(split);
		free_2d(split);
	}
	return (ret);
}

int		main(int ac, char **av, char **env)
{
	if (ac && av != NULL)
	{
		g_env = cp_env(env);
		minishel();
	}
	free_2d(g_env);
	return (0);
}
