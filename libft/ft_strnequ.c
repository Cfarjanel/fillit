/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:43:11 by emoreau           #+#    #+#             */
/*   Updated: 2017/11/23 16:31:29 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (!(s1) && !(s2))
		return (1);
	if (!(s1) || !(s2))
		return (0);
	if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	return (0);
}
