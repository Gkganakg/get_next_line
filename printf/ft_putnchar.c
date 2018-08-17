/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkganakg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:35:17 by gkganakg          #+#    #+#             */
/*   Updated: 2018/07/30 07:55:43 by gkganakg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnchar(char c, size_t n)
{
	size_t		i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
}
