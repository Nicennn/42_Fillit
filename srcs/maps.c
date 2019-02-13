/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 23:26:17 by niogden           #+#    #+#             */
/*   Updated: 2019/01/30 18:25:51 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_map(int size)
{
	int		i;
	int		j;
	char	**map;

	i = -1;
	if (!(map = (char **)ft_memalloc(sizeof(*map) * (size + 1))))
		return (NULL);
	while (++i < size)
	{
		if (!(map[i] = (char *)ft_strnew(sizeof(**map) * (size + 1))))
			return (NULL);
		j = -1;
		while (++j < size)
			map[i][j] = '.';
	}
	return (map);
}

void	free_map(char **map, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		ft_memdel((void **)&(map[i]));
	ft_memdel((void **)&map);
}

void	print_map(char **map, int size)
{
	int		i;

	i = 0;
	while (i < size)
		ft_putendl(map[i++]);
}
