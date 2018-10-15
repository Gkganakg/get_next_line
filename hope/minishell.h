/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:27:24 by gkganakg          #+#    #+#             */
/*   Updated: 2018/10/15 17:26:59 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include "libft/libft.h"

char **g_env;

typedef	struct		s_struct
{
	char	**hldr;
	pid_t	pid;
	int		ind;
	int		cnt;
	char	**hld;
	int		rett;
	char	*store1;
	char	*store2;

}					t_struct;

int					main(int ac, char **av, char **env);
char				**cp_env(char **envr);
int					env_len(char **envr);
int					free_2d(char **envr);

int					chck_commands(char **str);
int					update_env(char *key, char *value, int ind);
int					manage_env(char *key, char *value);
int					set_env(char **str);
int					print_env(char **env);
int					unset_env(char *str);
int					chck_env(char **str);

char				*capture_str(char *str);
int					search_str(char **env, char *key);
int					cd_funct(char **str);
void				saver2(char *str, int rett);
char				*new_envir2(char *n, char **arg);
void				saver(char **str, t_struct lin);
void				cd_dash();
void				set_pwd(char *str, char **tmp);
int					clear(void);
void				exec(char **str, char **env);
void				ret(int i);
void				ex(char *str, int i);
void				stupid(char *str);
#endif
