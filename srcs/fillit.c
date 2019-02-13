/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niogden <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 17:00:13 by niogden           #+#    #+#             */
/*   Updated: 2019/02/04 22:01:38 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char *av[])
{
	int				tetnb;
	t_tetriminos	tetri[26];

	if (ac != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	tetnb = ft_checker(av[1], tetri);
	if (tetnb == -1)
	{
		ft_putstr("error\n");
		return (1);
	}
	ft_goodformat(tetri, tetnb);
	fillit(tetri, tetnb);
	return (0);
}
