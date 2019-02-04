/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:05:21 by emoreau           #+#    #+#             */
/*   Updated: 2017/11/22 15:29:38 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	int		n;

	i = 0;
	n = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = i;
		n = 0;
		while (str[j] == to_find[n] && j < len)
		{
			j++;
			n++;
			if (!(to_find[n]))
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
