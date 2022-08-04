/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:36:27 by hfanzaou          #+#    #+#             */
/*   Updated: 2022/08/04 19:28:37 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "get_next_line/get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
typedef struct mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		w;
	int		h;
	char	**map;
	int		px;
	int		py;
	int		c;
	int		v;
	int		move;
	int		nx;
	int		i;
	int		nf;
}			t_mlx;

typedef struct s_vars
{
	int	fd;
	int	k;
	int	l;
	int	l2;
	int	e;
	int	c;
	int	p;
}		t_vars;

void	ft_putnbr(int n);
void	ft_openexit(t_mlx *ml);
char	*ft_itoa(int n);
int		ft_close(t_mlx *win);
int		ft_strchr(const char *s, int c);
int		loop_hooks(t_mlx *win);
void	ft_free(char **map);
void	ft_exit(char **map);
int		check_collections(char **map);
char	**to_map(char *str);
t_mlx	put_images(char **map, t_mlx win);
void	move_player(char m, t_mlx *win);
int		key_hook(int kcode, t_mlx *win);
int		checkmap(char *str);
int		ft_strlen2(char *s);
#endif
