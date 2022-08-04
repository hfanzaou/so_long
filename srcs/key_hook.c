/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:37:13 by hfanzaou          #+#    #+#             */
/*   Updated: 2022/08/04 19:27:46 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

int	check_if(t_mlx *ml, char cor, int i)
{	
	int		px;
	int		py;

	px = ml->px;
	py = ml->py;
	if (cor == 'x')
	{
		if ((ml->map[py][px + i] != '1' && ml->map[py][px + i] != 'E'))
			return (0);
		else if (ml->map[py][px + i] == 'E' && !check_collections(ml->map))
			return (0);
	}
	else if (cor == 'y')
	{
		if ((ml->map[py + i][px] != '1' && ml->map[py + i][px] != 'E'))
			return (0);
		else if (ml->map[py + i][px] == 'E' && !check_collections(ml->map))
			return (0);
	}
	return (1);
}

char	put_m(int kcode, t_mlx *ml)
{
	if ((kcode == 13 | kcode == 126) && !check_if(ml, 'y', -1))
		return ('U');
	else if ((kcode == 2 || kcode == 124) && !check_if(ml, 'x', 1))
		return ('R');
	else if ((kcode == 0 || kcode == 123) && !check_if(ml, 'x', -1))
		return ('L');
	else if ((kcode == 1 || kcode == 125) && !check_if(ml, 'y', 1))
		return ('D');
	else if (kcode == 53)
		ft_exit(ml->map);
	return ('0');
}

int	key_hook(int kcode, t_mlx *ml)
{
	char	m;
	char	*nm;

	m = put_m(kcode, ml);
	if (m != '0')
	{
		move_player(m, ml);
		ml->move++;
		nm = ft_itoa(ml->move);
		if (!nm)
			ft_exit(ml->map);
		ml->img = mlx_xpm_file_to_image(ml->mlx, "res/s.xpm", &ml->w, &ml->h);
		mlx_put_image_to_window(ml->mlx, ml->win, ml->img, 0, 0);
		mlx_string_put(ml->mlx, ml->win, 5, 9, 0X000000, nm);
		free(nm);
		write(1, "moves number : ", 15);
		ft_putnbr(ml->move);
		write(1, "\n", 1);
	}
	return (0);
}
