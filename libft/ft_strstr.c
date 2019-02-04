/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:26:55 by emoreau           #+#    #+#             */
/*   Updated: 2017/11/19 17:46:19 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *find)
{
	int		i;
	int		n;
	int		p;
	char	*s;

	i = 0;
	p = 0;
	s = (char *)str;
	if (!(find[i]))
		return (s);
	while (s[i])
	{
		n = 0;
		p = i;
		while (s[p] == find[n])
		{
			n++;
			p++;
			if (!(find[n]))
				return (&s[i]);
		}
		i++;
	}
	return (NULL);
}
