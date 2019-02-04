/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:05:47 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/28 18:19:04 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		min_size(int count)
{
	int size;

	size = 2;
	while (size * size < count * 4)
		size++;
	return (size);
}

int		init_temp(int cursor, int size)
{
	int i;

	while (cursor != size * size)
	{
		i = 0;
		while (i < size)
		{
			i++;
			if (cursor == ((i * size) - 1))
				return (cursor);
		}
		cursor++;
	}
	return (cursor);
}

/*
** fonction d'affichage d'une string de tetri
*/

void	puttetri(char *str)
{
	int i;
	int v;
	int x;
	int w;

	w = 0;
	i = 0;
	v = 1;
	x = ft_strlen(str);
	while (w * w < x)
		w++;
	while (str[i])
	{
		write(1, &str[i], 1);
		if (v == w)
		{
			v = 0;
			write(1, "\n", 1);
		}
		v++;
		i++;
	}
}

/*
** fonction qui place un tetri peu importe les donnes rentre
*/

char	*place_tetri(int curs, int size, char *tetri, char *map)
{
	t_pl_tr v;

	v.quatre = 0;
	v.stop = init_temp(curs, size) - curs + 1;
	v.i = 0;
	v.tmp_cursor = curs;
	if (v.stop >= 4)
		v.stop = 4;
	v.save_stop = v.stop;
	while (v.quatre++ != 4)
	{
		while (v.stop != 0)
		{
			if (tetri[v.i] != '.')
				map[curs] = tetri[v.i];
			curs++;
			v.i++;
			v.stop--;
		}
		v.stop = v.save_stop;
		curs = v.tmp_cursor + size;
		v.tmp_cursor = curs;
		v.i = v.quatre * 4;
	}
	return (map);
}
