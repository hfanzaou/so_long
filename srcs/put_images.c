/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:42:00 by hfanzaou          #+#    #+#             */
/*   Updated: 2022/08/04 19:28:07 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	push_pn(t_mlx *ml, char c, int x, int y)
{	
	if (c == 'P')
	{
		ml->img = mlx_xpm_file_to_image(ml->mlx, "res/0.xpm", &ml->w, &ml->h);
		if (!ml->img)
			return (1);
		mlx_put_image_to_window(ml->mlx, ml->win, ml->img, x, y);
		ml->img = mlx_xpm_file_to_image(ml->mlx, "res/P.xpm", &ml->w, &ml->h);
		ml->px = x / 50;
		ml->py = y / 50;
	}
	else
	{
		ml->img = mlx_xpm_file_to_image(ml->mlx, "res/0.xpm", &ml->w, &ml->h);
		if (!ml->img)
			return (1);
		mlx_put_image_to_window(ml->mlx, ml->win, ml->img, x, y);
		ml->img = mlx_xpm_file_to_image(ml->mlx, "res/N.xpm", &ml->w, &ml->h);
	}
	return (0);
}

int	push_images(t_mlx *ml, char c, int x, int y)
{
	if (c == '1')
		ml->img = mlx_xpm_file_to_image(ml->mlx, "res/1.xpm", &ml->w, &ml->h);
	else if (c == '0')
		ml->img = mlx_xpm_file_to_image(ml->mlx, "res/0.xpm", &ml->w, &ml->h);
	else if (c == 'C')
		ml->img = mlx_xpm_file_to_image(ml->mlx, "res/C.xpm", &ml->w, &ml->h);
	else if (c == 'P')
	{
		if (push_pn(ml, 'P', x, y))
			return (1);
	}
	else if (c == 'E')
		ml->img = mlx_xpm_file_to_image(ml->mlx, "res/E.xpm", &ml->w, &ml->h);
	else
	{
		if (push_pn(ml, 'N', x, y))
			return (1);
	}
	if (!ml->img)
		return (1);
	mlx_put_image_to_window(ml->mlx, ml->win, ml->img, x, y);
	return (0);
}

t_mlx	put_images(char **map, t_mlx ml)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = 0;
	y = 0;
	while (map[j])
	{
		i = 0;
		x = 0;
		while (map[j][i] && map[j][i] != '\n')
		{
			if (push_images(&ml, map[j][i], x, y))
				ft_exit(map);
			x += 50;
			i++;
		}
		y += 50;
		j++;
	}
	return (ml);
}
