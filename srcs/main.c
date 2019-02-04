/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:50:35 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/28 17:51:36 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

static int	ft_fillit(char *map)
{
	char	**smap;
	int		nbr;

	if (check_valid_file(map))
	{
		nbr = count_tetri(map);
		smap = tab_all_tetri(map);
		if (nbr <= 26)
		{
			up_left(smap, nbr);
			ft_replace_char_all(smap);
			if (solve(nbr, smap, min_size(nbr)))
				return (1);
		}
	}
	return (0);
}

int			main(int argc, char **argv)
{
	char	*map;
	int		fd;

	if (argc != 2)
	{
		ft_putstr("too few or too many arguments\n");
		return (0);
	}
	if ((fd = ft_open(argv[1])) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	map = ft_read(fd);
	if (ft_fillit(map))
		return (0);
	ft_putendl("error");
	return (0);
}
