/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:07:33 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/28 17:50:48 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

/*
** fonction qui alloue et remplis la lib de point
*/

static char		*alloc_map(char *map, size_t size)
{
	if (map)
		free(map);
	if (!(map = (char*)malloc(sizeof(char) * (size * size + 1))))
		return (0);
	ft_memset(map, '.', size * size);
	map[size * size] = '\0';
	return (map);
}

static char		*try(t_var_struct_try var, int size, char **tetris, int t)
{
	int			i;
	char		*temp;

	i = 0;
	while (i < size * size)
	{
		if (check_valid_pos(i, size, tetris[t], var.map))
		{
			var.map = place_tetri(i, size, tetris[t], var.map);
			if (t + 1 == var.count)
				return (var.map);
			temp = try(var, size, tetris, t + 1);
			if (temp)
				return (temp);
			else
				ft_replace_char(var.map, 'A' + t, '.');
		}
		i++;
	}
	return (0);
}

int				solve(int count, char **tab, int size)
{
	char				*temp;
	t_var_struct_try	var;

	var.count = count;
	while (size < 20)
	{
		var.map = NULL;
		if (!(var.map = alloc_map(var.map, size)))
			return (0);
		temp = try(var, size, tab, 0);
		if (temp)
		{
			puttetri(temp);
			return (1);
		}
		size++;
	}
	return (0);
}

/*
** fonction qui cree un tab ** avec dans chaque string un tetriminos sans \n
*/

char			**tab_all_tetri(char *map)
{
	size_t	i;
	size_t	j;
	char	**smap;
	char	**ret;

	j = 0;
	i = 0;
	if (!(ret = malloc(sizeof(map))))
		return (NULL);
	smap = ft_strsplit(map, '\n');
	while (smap[j])
	{
		ret[i] = ft_strjoin(smap[j], smap[j + 1]);
		ret[i] = ft_strjoin(ret[i], smap[j + 2]);
		ret[i] = ft_strjoin(ret[i], smap[j + 3]);
		i++;
		j += 4;
	}
	ret[i] = 0;
	return (ret);
}
