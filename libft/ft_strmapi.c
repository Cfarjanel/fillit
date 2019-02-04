/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:40:49 by emoreau           #+#    #+#             */
/*   Updated: 2017/11/17 14:12:16 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*dest;

	if (s)
	{
		i = 0;
		len = 0;
		while (s[len])
			len++;
		if (!(dest = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s[i])
		{
			dest[i] = f(i, s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
