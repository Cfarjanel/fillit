/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emoreau <emoreau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 16:33:57 by emoreau           #+#    #+#             */
/*   Updated: 2018/02/28 18:18:58 by emoreau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct		s_variable
{
	int i;
	int temp_cursor;
	int temp_i;
	int nbdiez;
	int cursor;
}					t_variable;

typedef struct		s_pl_tr
{
	int tmp_cursor;
	int quatre;
	int stop;
	int save_stop;
	int i;
}					t_pl_tr;

typedef struct		s_var_struct_try
{
	int		count;
	char	*map;
}					t_var_struct_try;

int					ft_open(char *name);
char				*ft_read(int fd);
int					count_tetri(char *map);
int					check_vali(char *map);
char				**tab_all_tetri(char *map);
char				**init_tetritype(void);
int					check_valid_tetri(char **tab, int nb, char **tetritype);
int					check_valid_tetri_nb_diez(char **tab, int count);
void				ft_replace_char(char *s, char a, char b);
void				up_left(char **tab, int count);
void				ft_replace_char_all(char **tab);
char				*place_tetri(int pos, int taille_map, char *tetri,
					char *map);
int					min_size(int n);
int					solve(int count, char **tab, int size);
int					check_valid_file(char *str);
int					check_valid_pos(int curs, int size, char *tetri, char *map);
int					init_temp(int cursor, int size);
void				puttetri(char *str);

#endif
