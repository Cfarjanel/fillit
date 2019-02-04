/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:01:00 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/27 16:11:45 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static t_variable	checker(t_variable var, int size, int curs, int k)
{
	while (var.cursor != var.temp_cursor || var.i != var.temp_i)
	{
		if (var.cursor != var.temp_cursor)
			var.cursor++;
		if (var.i != var.temp_i)
			var.i++;
	}
	while (var.cursor != curs + size * k)
		var.cursor++;
	var.i++;
	var.temp_cursor += size;
	var.temp_i += 4;
	return (var);
}

int					check_valid_pos(int curs, int size, char *tetri, char *map)
{
	t_variable	var;
	int			k;

	var.i = 0;
	var.nbdiez = 0;
	var.cursor = curs;
	var.temp_cursor = init_temp(var.cursor, size);
	var.temp_i = 3;
	k = 1;
	while (tetri[var.i] && map[var.cursor])
	{
		while (var.i != var.temp_i && var.cursor != var.temp_cursor)
		{
			if (tetri[var.i] != '.' && map[var.cursor] == '.')
				var.nbdiez++;
			var.i++;
			var.cursor++;
		}
		if (tetri[var.i] != '.' && map[var.cursor] == '.')
			var.nbdiez++;
		var = checker(var, size, curs, k);
		k++;
	}
	return ((var.nbdiez == 4) ? 1 : 0);
}

int					count_tetri(char *map)
{
	int count;
	int i;
	int k;

	count = 1;
	i = 0;
	k = 0;
	while (map[i])
	{
		if (k == 20)
		{
			k = 0;
			count++;
			i++;
		}
		k++;
		i++;
	}
	return (count);
}

/*
** les deux fonctions permettent de changer les # en caracteres
*/

void				ft_replace_char(char *str, char r, char c)
{
	size_t i;

	i = 0;
	if (str)
		while (str[i])
		{
			if (str[i] == r)
				str[i] = c;
			i++;
		}
}

void				ft_replace_char_all(char **map)
{
	size_t	i;
	char	c;

	i = 0;
	c = 'A';
	while (map[i])
	{
		ft_replace_char(map[i], '#', c);
		i++;
		c++;
	}
}
