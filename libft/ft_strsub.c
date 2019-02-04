/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:54:54 by emoreau           #+#    #+#             */
/*   Updated: 2017/11/17 14:12:43 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s)
	{
		i = 0;
		if (!(new = (char *)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len)
		{
			new[i] = s[start];
			i++;
			start++;
		}
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
