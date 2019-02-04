/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:09:02 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/28 17:52:38 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

void	up_line(char *str)
{
	while (!ft_strnstr(str, "#", 4))
	{
		ft_memmove(str, str + 4, 12);
		ft_memset(str + 12, '.', 4);
	}
}

void	left_col(char *str)
{
	while (str[0] != '#' && str[4] != '#' && str[8] != '#' && str[12] != '#')
	{
		ft_memmove(str, str + 1, 3);
		str[3] = '.';
		ft_memmove(str + 4, str + 5, 3);
		str[7] = '.';
		ft_memmove(str + 8, str + 9, 3);
		str[11] = '.';
		ft_memmove(str + 12, str + 13, 3);
		str[15] = '.';
	}
}

void	up_left(char **tab, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		up_line(tab[i]);
		left_col(tab[i++]);
	}
}
