/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 13:21:14 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/14 13:23:48 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



char	**add_env_var(char **env, char *var)
{
	int		i;
	int		size;
	char	**new;

	i = 0;
	size = ft_2d_strlen(env) + 1;
	new = (char **)malloc(sizeof(char *) * size + 1);
	if (new == NULL)
		return (NULL);
	while (i < size - 1)
	{
		new[i] = ft_strdup(env[i]);
		i++;
	}
	new[i] = ft_strdup(var);
	new[i + 1] = NULL;
	free_2d_arr(env);
	return (new);
}
