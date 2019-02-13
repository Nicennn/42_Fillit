/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrestey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 12:50:01 by rcrestey          #+#    #+#             */
/*   Updated: 2019/01/29 20:19:35 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	zerotab(int *tab, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		tab[i] = 0;
}

static int	ft_checkbloc(char *line, int bloc[5])
{
	int		i;
	int		start;
	int		isintouch;

	i = -1;
	isintouch = 0;
	start = bloc[0];
	while (line[++i])
	{
		if (line[i] == '#')
		{
			if (bloc[0] != start && line[i - 1] != '#')
				return (1);
			if (bloc[i + 1] == 1)
				isintouch = 1;
			bloc[0]++;
			bloc[i + 1] = 1;
		}
		else
			bloc[i + 1] = 0;
		if (bloc[0] > 4)
			return (1);
	}
	return ((isintouch != 1 && start > 0 && start < 4 ? 1 : 0));
}

static int	ft_checkchar(char *line, int *linenb, int *tetnb, int bloc[5])
{
	int		i;

	i = -1;
	while (line[++i])
		if (line[i] != '.' && line[i] != '#')
			return (1);
	(*linenb)++;
	if (*linenb % 5 == 0 && line[0] == '\0')
	{
		(*tetnb)++;
		if (bloc[0] < 4)
			return (1);
		zerotab(bloc, 5);
		return (0);
	}
	else if (*linenb % 5 != 0 && i == 4)
		return (ft_checkbloc(line, bloc));
	return (1);
}

int			ft_checker(char *file, t_tetriminos *tetri)
{
	int		fd;
	int		linenb;
	int		tetnb;
	int		bloc[5];
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (-1);
	linenb = 0;
	tetnb = 1;
	zerotab(bloc, 5);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_checkchar(line, &linenb, &tetnb, bloc) || tetnb > 26)
			return (-1);
		ft_data(tetri, tetnb, linenb, bloc);
		free(line);
	}
	free(line);
	if (tetnb * 5 - 1 != linenb)
		return (-1);
	else if (tetnb * 5 - 1 == linenb && bloc[0] != 4)
		return (-1);
	return (close(fd) == -1 ? -1 : tetnb);
}
