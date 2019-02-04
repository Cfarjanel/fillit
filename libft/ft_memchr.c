/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:52:20 by emoreau           #+#    #+#             */
/*   Updated: 2017/11/19 19:49:31 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	unsigned char			p;
	unsigned char			*l;

	p = (unsigned char)c;
	l = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (l[i] != p)
			i++;
		else
			return (&l[i]);
	}
	return (NULL);
}
