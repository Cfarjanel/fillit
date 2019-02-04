/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:14:31 by emoreau           #+#    #+#             */
/*   Updated: 2017/11/22 16:03:56 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	int				end;
	int				n;

	i = 0;
	n = 0;
	if (s)
	{
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (i == ft_strlen(s))
			return (ft_strdup("\0"));
		end = ft_strlen(s) - 1;
		while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
			end--;
		return (ft_strsub(s, i, (end - i + 1)));
	}
	return (NULL);
}
