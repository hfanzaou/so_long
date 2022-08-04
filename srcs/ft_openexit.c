/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_openexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 19:27:06 by hfanzaou          #+#    #+#             */
/*   Updated: 2022/08/04 19:27:08 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

void	ft_openexit(t_mlx *ml)
{
	void	*img;
	int		i;
	int		j;

	img = mlx_xpm_file_to_image(ml->mlx, "res/E0.xpm", &ml->w, &ml->h);
	if (!img)
		ft_exit(ml->map);
	i = 0;
	while (ml->map[i])
	{
		j = 0;
		while (ml->map[i][j])
		{
			if (ml->map[i][j] == 'E')
				mlx_put_image_to_window(ml->mlx, ml->win, img, j * 50, i * 50);
			j++;
		}
		i++;
	}
	ml->c = 0;
}
