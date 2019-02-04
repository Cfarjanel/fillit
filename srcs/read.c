/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:30:11 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/27 15:03:21 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int		ft_open(char *name)
{
	int		fd;

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	return (fd);
}

char	*ft_read(int fd)
{
	char	*buf;
	int		g;

	if (!(buf = malloc(sizeof(char *) * 4096 + 1)))
		return (NULL);
	g = (int)read(fd, buf, 4096);
	buf[g] = '\0';
	return (buf);
}
