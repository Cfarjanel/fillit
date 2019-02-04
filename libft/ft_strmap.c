/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:40:32 by emoreau           #+#    #+#             */
/*   Updated: 2017/11/17 13:44:21 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			dest[i] = f(s[i]);
			i++;
		}
		dest[i] = '\0';
		return (dest);
	}
	return (NULL);
}
