/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:40:04 by hfanzaou          #+#    #+#             */
/*   Updated: 2022/08/04 19:28:00 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	push_ms(void *m2, int i, t_mlx *ml, char c)
{
	if (c == 'X' || c == 'x')
	{
		mlx_put_image_to_window(ml->mlx, ml->win, ml->img, i, ml->py * 50);
		mlx_put_image_to_window(ml->mlx, ml->win, m2, i, ml->py * 50);
	}
	else
	{
		mlx_put_image_to_window(ml->mlx, ml->win, ml->img, ml->px * 50, i);
		mlx_put_image_to_window(ml->mlx, ml->win, m2, ml->px * 50, i);
	}
}

int	switch_images(int i, char c, t_mlx *ml)
{
	void	*m2;
	void	*m3;

	ml->img = mlx_xpm_file_to_image(ml->mlx, "res/0.xpm", &ml->w, &ml->h);
	m2 = mlx_xpm_file_to_image(ml->mlx, "res/P.xpm", &ml->w, &ml->h);
	m3 = mlx_xpm_file_to_image(ml->mlx, "res/PL.xpm", &ml->w, &ml->h);
	if (!ml->img || !m2 || !m3)
		return (1);
	mlx_put_image_to_window(ml->mlx, ml->win,
		ml->img, ml->px * 50, ml->py * 50);
	if (c == 'x')
		push_ms(m2, i, ml, c);
	else if (c == 'X' || c == 'y')
		push_ms(m3, i, ml, c);
	return (0);
}

int	what_image(char m, t_mlx *ml)
{
	int	i;

	i = 0;
	if (m == 'U')
	{
		i = switch_images((ml->py - 1) * 50, 'y', ml);
		ml->py = ml->py - 1;
	}
	else if (m == 'R')
	{
		i = switch_images((ml->px + 1) * 50, 'X', ml);
		ml->px = ml->px + 1;
	}
	else if (m == 'L')
	{
		i = switch_images((ml->px - 1) * 50, 'x', ml);
		ml->px = ml->px - 1;
	}
	else if (m == 'D')
	{
		i = switch_images((ml->py + 1) * 50, 'y', ml);
		ml->py = ml->py + 1;
	}
	return (i);
}

void	change_position(char m, t_mlx *ml, int pox, int poy)
{
	if (m == 'U')
	{
		ml->map[poy][pox] = '0';
		ml->map[poy - 1][pox] = 'P';
	}
	else if (m == 'R')
	{
		ml->map[poy][pox] = '0';
		ml->map[poy][pox + 1] = 'P';
	}
	else if (m == 'L')
	{
		ml->map[poy][pox] = '0';
		ml->map[poy][pox - 1] = 'P';
	}
	else if (m == 'D')
	{
		ml->map[poy][pox] = '0';
		ml->map[poy + 1][pox] = 'P';
	}
}

void	move_player(char m, t_mlx *ml)
{
	int	pox;
	int	poy;

	pox = ml->px;
	poy = ml->py;
	if (what_image(m, ml))
		ft_exit(ml->map);
	if ((ml->map[ml->py][ml->px] == 'E' && !check_collections(ml->map))
		|| ml->map[ml->py][ml->px] == 'N')
		ft_exit(ml->map);
	change_position(m, ml, pox, poy);
	if (!check_collections(ml->map))
		ft_openexit(ml);
}
