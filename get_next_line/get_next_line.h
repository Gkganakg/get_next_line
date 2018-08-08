/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <gkganakg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:12:23 by gkganakg          #+#    #+#             */
/*   Updated: 2018/06/28 11:00:02 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 33
# include "libft/libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int		get_next_line(int const fd, char **line);

#endif
