/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 21:21:01 by niogden           #+#    #+#             */
/*   Updated: 2019/02/04 22:17:25 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	place_tetri(t_tetriminos *tetri, char **map, int i, int j)
{
	int		k;

	k = 0;
	while (k < 7)
	{
		map[tetri->pos[k + 1] + i][tetri->pos[k] + j] = tetri->lettre;
		k += 2;
	}
}

static int	verif(t_tetriminos *tetri, char **map, int x, int y)
{
	int		i;

	i = 0;
	while (i < 7)
	{
		if (x + tetri->pos[i] < 0 || y + tetri->pos[i + 1] < 0)
			return (0);
		if (map[tetri->pos[i + 1] + y][tetri->pos[i] + x] != '.')
			return (0);
		i += 2;
	}
	place_tetri(tetri, map, y, x);
	return (1);
}

static void	tetri_del(t_tetriminos *tetri, char **map, int x, int y)
{
	char	c;

	c = tetri->lettre;
	tetri->lettre = '.';
	place_tetri(tetri, map, y, x);
	tetri->lettre = c;
}

static int	solver(char **map, t_tetriminos *tetri, int size, int tetnb)
{
	int		x;
	int		y;

	y = 0;
	if (tetri->lettre < 'A' || tetri->lettre > 'Z')
		return (1);
	while (y <= size - tetri->height)
	{
		x = 0;
		while (x < size)
		{
			if (verif(tetri, map, x, y))
			{
				if (solver(map, tetri + 1, size, tetnb))
					return (1);
				else
					tetri_del(tetri, map, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void		fillit(t_tetriminos *tetri, int tetnb)
{
	char	**map;
	int		size;

	size = 2;
	map = create_map(size);
	while (!solver(map, tetri, size, tetnb))
	{
		free_map(map, size);
		size++;
		map = create_map(size);
	}
	print_map(map, size);
	free_map(map, size);
}
