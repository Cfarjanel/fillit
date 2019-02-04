/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:03:22 by emoreau           #+#    #+#             */
/*   Updated: 2017/11/17 14:16:39 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		n;
	char	*new;

	i = -1;
	n = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s1)
											+ ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[++i])
	{
		new[n] = s1[i];
		n++;
	}
	i = 0;
	while (s2[i])
	{
		new[n] = s2[i];
		n++;
		i++;
	}
	new[n] = '\0';
	return (new);
}
