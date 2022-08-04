/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:48:03 by hfanzaou          #+#    #+#             */
/*   Updated: 2022/08/04 19:27:54 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	put_enemy(t_mlx *ml, int x, int y, int f)
{
	void	*img1;
	void	*img2;
	void	*img3;

	img1 = mlx_xpm_file_to_image(ml->mlx, "res/0.xpm", &ml->w, &ml->h);
	img2 = mlx_xpm_file_to_image(ml->mlx, "res/NL.xpm", &ml->w, &ml->h);
	img3 = mlx_xpm_file_to_image(ml->mlx, "res/N.xpm", &ml->w, &ml->h);
	if (!img1 || !img1 || !img3)
		return (1);
	if (f == 0)
	{
		mlx_put_image_to_window(ml->mlx, ml->win, img1, x * 50, y * 50);
		mlx_put_image_to_window(ml->mlx, ml->win, img2, (x + 1) * 50, y * 50);
	}
	else
	{
		mlx_put_image_to_window(ml->mlx, ml->win, img1, x * 50, y * 50);
		mlx_put_image_to_window(ml->mlx, ml->win, img3, (x - 1) * 50, y * 50);
	}
	return (0);
}

int	move_enemy(t_mlx *ml, int x, int y, int *f)
{
	if (ml->map[y][x + 1] != '0' && ml->map[y][x + 1] != 'P')
		*f = 1;
	else if (ml->map[y][x - 1] != '0' && ml->map[y][x - 1] != 'P')
		*f = 0;
	if (put_enemy(ml, x, y, *f))
		ft_exit(ml->map);
	if (*f == 0)
	{
		if (ml->map[y][x + 1] == 'P')
			ft_exit(ml->map);
		ml->map[y][x + 1] = 'N';
		ml->map[y][x] = '0';
	}
	else if (*f == 1)
	{
		if (ml->map[y][x - 1] == 'P')
			ft_exit(ml->map);
		ml->map[y][x - 1] = 'N';
		ml->map[y][x] = '0';
	}
	return (*f);
}

int	loop_hooks(t_mlx *ml)
{
	int	i;
	int	j;

	if (ml->i == 2000)
	{
		i = 0;
		while (ml->map[i])
		{
			j = 0;
			while (ml->map[i][j])
			{
				if (ml->map[i][j] == 'N')
				{
					if (!move_enemy(ml, j, i, &ml->nf))
						j++;
				}
				j++;
			}
			i++;
		}
		ml->i = 0;
	}
	ml->i++;
	return (0);
}
