/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrestey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 20:03:12 by rcrestey          #+#    #+#             */
/*   Updated: 2019/02/01 19:18:17 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_size_width(t_tetriminos *tetri, int tetnb)
{
	int		i;
	int		j;
	int		diff[2];

	i = -1;
	j = -1;
	while (++i < tetnb)
	{
		diff[0] = tetri[i].pos[0];
		diff[1] = tetri[i].pos[0];
		while (++j < 8)
		{
			if (j % 2 == 0)
			{
				if (tetri[i].pos[j] < diff[0])
					diff[0] = tetri[i].pos[j];
				if (tetri[i].pos[j] > diff[1])
					diff[1] = tetri[i].pos[j];
			}
		}
		tetri[i].width = diff[1] - diff[0] + 1;
		j = -1;
	}
}

static void		ft_size_height(t_tetriminos *tetri, int tetnb)
{
	int		i;
	int		j;
	int		diff[2];

	i = -1;
	j = -1;
	while (++i < tetnb)
	{
		diff[0] = tetri[i].pos[1];
		diff[1] = tetri[i].pos[1];
		while (++j < 8)
		{
			if (j % 2 != 0)
			{
				if (tetri[i].pos[j] < diff[0])
					diff[0] = tetri[i].pos[j];
				if (tetri[i].pos[j] > diff[1])
					diff[1] = tetri[i].pos[j];
			}
		}
		tetri[i].height = diff[1] - diff[0] + 1;
		j = -1;
	}
}

void			ft_goodformat(t_tetriminos *tetri, int tetnb)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = -1;
	while (++i < tetnb)
	{
		j = -1;
		x = tetri[i].pos[0];
		y = tetri[i].pos[1];
		while (++j < 8)
		{
			if (j % 2 == 0)
				tetri[i].pos[j] = tetri[i].pos[j] - x;
			else
				tetri[i].pos[j] = tetri[i].pos[j] - y;
		}
	}
	ft_size_height(tetri, tetnb);
	ft_size_width(tetri, tetnb);
}

void			ft_data(t_tetriminos *tetri, int tetnb, int linenb, int bloc[5])
{
	int		i;
	int		j;

	i = 5;
	j = 0;
	while (--i > 0)
	{
		if (bloc[i])
		{
			j++;
			tetri[tetnb - 1].pos[2 * (bloc[0] - j)] = i;
			tetri[tetnb - 1].pos[2 * (bloc[0] - j) + 1] = linenb % 5;
			tetri[tetnb - 1].lettre = 'A' + tetnb - 1;
		}
	}
}
