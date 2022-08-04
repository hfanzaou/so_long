/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:39:59 by hfanzaou          #+#    #+#             */
/*   Updated: 2022/08/04 19:26:37 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	ft_error(int i)
{
	if (i == 0)
		write(2, "Error\nInvalid map\n", 18);
	else if (i == 1)
		write(2, "Error\nInvalid path\n", 19);
	else if (i == 2)
		write(2, "Error\nEmpty map\n", 16);
	exit(1);
	return (0);
}

int	ft_strlen2(char *s)
{
	int		i;
	int		fd;
	char	*l;

	fd = open(s, O_RDONLY);
	l = get_next_line(fd);
	if (!l)
		ft_error(2);
	i = 0;
	while (l)
	{
		i++;
		free(l);
		l = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	ft_pathcmp(char *str1, char *str2, int fd)
{
	int	i;
	int	j;

	i = 0;
	j = 3;
	while (str1[i + 1])
		i++;
	while (j > 0 && str1[i] == str2[j])
	{
		i--;
		j--;
	}
	if (fd <= 0)
		ft_error(1);
	if (j)
		ft_error(1);
	return (0);
}

int	ft_conditions(char *line, int i, t_vars *g)
{
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != '1' && (g->k == 0 || g->k == g->l2 - 1))
			return (ft_error(0));
		else if (line[i] != '1' && (i == 0 || line[i + 1] == '\n'))
			return (ft_error(0));
		else if (!ft_strchr("10ECPN", line[i]))
			return (ft_error(0));
		else
		{
			if (line[i] == 'E')
				g->e++;
			else if (line[i] == 'C')
				g->c++;
			else if (line[i] == 'P')
				g->p++;
		}
		i++;
	}
	if (((!line[i] || line[i] == '\n') && i != g->l - 1))
		ft_error(0);
	return (0);
}

int	checkmap(char *str)
{
	t_vars	g;
	char	*line;
	int		i;

	g.fd = open(str, O_RDONLY);
	ft_pathcmp(str, ".ber", g.fd);
	g.l2 = ft_strlen2(str);
	g.k = 0;
	g.e = 0;
	g.c = 0;
	g.p = 0;
	i = 0;
	line = get_next_line(g.fd);
	g.l = ft_strlen(line);
	while (g.k < g.l2)
	{	
		ft_conditions(line, i, &g);
		free(line);
		line = get_next_line(g.fd);
		g.k++;
	}
	if (!g.c || g.p != 1 || !g.e)
		return (ft_error(0));
	close(g.fd);
	return (g.l);
}
