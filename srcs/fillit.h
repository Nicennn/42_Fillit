/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 16:55:43 by niogden           #+#    #+#             */
/*   Updated: 2019/02/04 22:18:32 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>

typedef	struct	s_tetriminos
{
	char		lettre;
	int			height;
	int			width;
	int			pos[8];
}				t_tetriminos;

void			ft_data(t_tetriminos *tetri, int tetnb, int linenb,
		int bloc[5]);
void			ft_goodformat(t_tetriminos *tetri, int tetnb);
void			print_map(char **map, int size);
int				ft_checker(char *file, t_tetriminos *tetriminos);
char			**create_map(int size);
void			free_map(char **map, int size);
void			fillit(t_tetriminos *tetri, int tetnb);

#endif
