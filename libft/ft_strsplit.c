/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 14:25:26 by emoreau           #+#    #+#             */
/*   Updated: 2017/11/23 16:29:35 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		comptmots(const char *str, char c)
{
	int i;
	int mots;

	i = 0;
	mots = 0;
	if (!(str))
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			mots++;
		while (str[i] != c && str[i])
			i++;
	}
	return (mots);
}

static int		comptl(const char *str, char c, int i)
{
	int compt;

	compt = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		compt++;
	}
	return (compt);
}

static char		**ft_magic(char const *str, char c, int i, char **tab)
{
	int k;
	int j;

	j = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
		{
			k = 0;
			if (!(tab[j] = (char*)malloc(sizeof(char) *\
				(comptl(str, c, i) + 1))))
				return (NULL);
			while (str[i] != c && str[i])
			{
				tab[j][k] = str[i];
				k++;
				i++;
			}
			tab[j++][k] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}

char			**ft_strsplit(char const *str, char c)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(str))
		return (NULL);
	if (!(tab = (char**)malloc(sizeof(char*) * (comptmots(str, c) + 1))))
		return (NULL);
	tab = ft_magic(str, c, i, tab);
	return (tab);
}
