/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:14:57 by emoreau           #+#    #+#             */
/*   Updated: 2017/11/14 18:26:53 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int len_s;

	len_s = ft_strlen(s);
	while ((len_s >= 0) && (s[len_s] != (char)c))
		len_s--;
	if (s[len_s] == c)
		return ((char *)&s[len_s]);
	else
		return (NULL);
}
