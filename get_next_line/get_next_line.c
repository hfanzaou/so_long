/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 02:23:29 by hfanzaou          #+#    #+#             */
/*   Updated: 2021/12/05 00:52:36 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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
	static char	*c;
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	c = read_buff(c, fd);
	if (!c)
		return (NULL);
	l = line_buff(c);
	if (!*l)
	{
		free(l);
		return (NULL);
	}
	c = save_buff(c);
	return (l);
}
