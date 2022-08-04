/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:53:49 by hfanzaou          #+#    #+#             */
/*   Updated: 2022/08/04 19:28:26 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int ac, char **av)
{
	t_mlx	ml;
	int		le;

	if (ac != 2)
		return (1);
	le = checkmap(av[1]);
	if (!le)
		return (1);
	ml.map = to_map(av[1]);
	ml.mlx = mlx_init();
	if (!ml.mlx)
		return (1);
	ml.win = mlx_new_window(ml.mlx, (le - 1) * 50,
			ft_strlen2(av[1]) * 50, "so_long");
	ml = put_images(ml.map, ml);
	mlx_key_hook(ml.win, key_hook, &ml);
	mlx_hook(ml.win, 17, 0, ft_close, &ml);
	mlx_loop_hook(ml.mlx, loop_hooks, &ml);
	mlx_loop(ml.mlx);
	system("leaks so_long");
	return (0);
}
