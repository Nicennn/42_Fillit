/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrestey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:24:50 by rcrestey          #+#    #+#             */
/*   Updated: 2018/12/17 13:26:28 by rcrestey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/fillit.h"

char	*ft_strnjoin(char *line, char *tmp, size_t n)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!(str = ft_strnew(ft_strlen(line) + n)))
		return (NULL);
	i = -1;
	while (line[++i])
		str[i] = line[i];
	j = -1;
	while (tmp[++j] && j < n)
		str[i + j] = tmp[j];
	return (str);
}

int		get_line(char **line, char *tmp)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (tmp[i] != '\n' && tmp[i])
		i++;
	temp = *line;
	if (!(*line = ft_strnjoin(*line, tmp, i)))
		return (-1);
	free(temp);
	if (tmp[i] == '\n')
		return (1);
	return (0);
}

int		clear(int fd, char ***tmp, int isline)
{
	char	*temp;

	temp = *(*(tmp) + fd);
	if (isline)
		*(*(tmp) + fd) = ft_strdup(ft_strchr(*(*(tmp) + fd), '\n') + 1);
	else
		*(*(tmp) + fd) = ft_strdup("");
	free(temp);
	return (1);
}

int		ft_read(int fd, char **line, char ***tmp)
{
	int			ret;
	char		buff[BUFF_SIZE + 1];
	char		*temp;

	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if (get_line(line, buff))
		{
			temp = *(*(tmp) + fd);
			*(*(tmp) + fd) = ft_strjoin(temp, ft_strchr(buff, '\n') + 1);
			free(temp);
			return (1);
		}
	}
	if (**line)
		return (1);
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	**tmp = NULL;

	if (!line || fd < 0 || fd >= OPEN_MAX || BUFF_SIZE <= 0)
		return (-1);
	if (!tmp)
		if (!(tmp = malloc(OPEN_MAX)))
			return (-1);
	if (!tmp[fd])
		if (!(tmp[fd] = ft_strdup("")))
			return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	if (*tmp[fd])
	{
		if (get_line(line, tmp[fd]))
			return ((clear(fd, &tmp, 1)));
		clear(fd, &tmp, 0);
	}
	return (ft_read(fd, line, &tmp));
}
