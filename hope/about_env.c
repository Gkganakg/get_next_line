/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aboutt_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 10:55:28 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/15 12:22:48 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		free_2d(char **envr)
{
	int len;

	if (!envr)
		return (1);
	len = 0;
	while (envr[len])
	{
		free(envr[len]);
		len++;
	}
	if (envr != NULL)
		free(envr);
	return (1);
}

int		env_len(char **envr)
{
	int len;

	if (envr)
	{
		len = 0;
		while (envr[len])
			len++;
		return (len);
	}
	return (0);
}

char	**cp_env(char **envr)
{
	char	**dup;
	int		len;
	int		arr_size;
	int		i;

	arr_size = env_len(envr);
	dup = (char**)malloc(sizeof(char*) * (arr_size + 1));
	if (dup)
	{
		i = 0;
		while (i < arr_size)
		{
			len = ft_strlen(envr[i]);
			dup[i] = (char*)malloc(sizeof(char) * (len + 1));
			if (dup[i])
				ft_strcpy(dup[i], envr[i]);
			i++;
		}
		dup[i] = NULL;
	}
	return (dup);
}
