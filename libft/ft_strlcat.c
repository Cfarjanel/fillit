/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:09:50 by emoreau           #+#    #+#             */
/*   Updated: 2017/11/23 16:31:16 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t len_d;
	size_t len_s;
	size_t i;

	i = 0;
	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	if ((len_d + 1) > size)
		return (len_s + size);
	while (src[i] != '\0' && (len_d + 1) < size)
	{
		dst[len_d + i] = src[i];
		i++;
		size--;
	}
	dst[len_d + i] = '\0';
	if (src[i] == '\0')
		return (i + len_d);
	return (len_d + len_s);
}
