/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:24:58 by hfanzaou          #+#    #+#             */
/*   Updated: 2021/12/04 22:55:00 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_buff(char *c, int fd)
{
	int		i;
	char	*t;

	t = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!t)
		return (NULL);
	i = 1;
	while (ft_cmp(c, '\n') && i > 0)
	{
		i = read(fd, t, BUFFER_SIZE);
		if (i == -1 || (!i && !c))
		{
			free(t);
			return (NULL);
		}
		t[i] = '\0';
		c = ft_strjoin(c, t);
	}
	free(t);
	return (c);
}

char	*line_buff(char *c)
{
	int		i;
	char	*l;

	i = 0;
	if (*c == '\0')
		return (c);
	while (c[i] && c[i] != '\n')
		i++;
	if (c[i] == '\n')
		i++;
	l = malloc(sizeof(char) * (i + 1));
	if (!l)
		return (NULL);
	i = 0;
	while (c[i])
	{
		l[i] = c[i];
		i++;
		if (c[i - 1] == '\n')
			break ;
	}
	l[i] = '\0';
	return (l);
}

char	*save_buff(char *c)
{
	int		i;
	char	*s;

	i = 0;
	while (c[i] && c[i] != '\n')
		i++;
	if (!c[i])
	{
		free(c);
		return (NULL);
	}
	s = ft_substr(c, i + 1, ft_strlen(c) - i);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*c[OPEN_MAX];
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= OPEN_MAX)
		return (NULL);
	c[fd] = read_buff(c[fd], fd);
	if (!c[fd])
		return (NULL);
	l = line_buff(c[fd]);
	if (!*l)
	{
		free(l);
		return (NULL);
	}
	c[fd] = save_buff(c[fd]);
	return (l);
}
