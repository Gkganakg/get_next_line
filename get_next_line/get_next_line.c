/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 17:20:46 by gkganakg          #+#    #+#             */
/*   Updated: 2018/06/28 10:59:08 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check(int fd, char **line, char **store)
{
	int		index;
	char	*temp;

	index = 0;
	while (store[fd][index] != '\n' && store[fd][index] != '\0')
		index++;
	if (store[fd][index] == '\0')
	{
		*line = ft_strdup(store[fd]);
		ft_strdel(&store[fd]);
	}
	else if (store[fd][index] == '\n')
	{
		*line = ft_strsub(store[fd], 0, index);
		temp = ft_strdup(&store[fd][index + 1]);
		free(store[fd]);
		store[fd] = temp;
		if (store[fd][0] == '\0')
			ft_strdel(&store[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*store[255];
	char			buff[BUFF_SIZE + 1];
	int				r_bytes;
	char			*temp;

	if (fd < 0 || !line)
		return (-1);
	while ((r_bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r_bytes] = '\0';
		if (store[fd] == NULL)
			store[fd] = ft_strnew(1);
		temp = ft_strjoin(store[fd], buff);
		free(store[fd]);
		store[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (r_bytes < 0)
		return (-1);
	else if (r_bytes == 0 && (store[fd] == NULL || store[fd][0] == '\0'))
		return (0);
	return (ft_check(fd, line, store));
}
