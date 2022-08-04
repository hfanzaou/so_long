/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:43:38 by hfanzaou          #+#    #+#             */
/*   Updated: 2022/08/04 19:28:16 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

char	**to_map(char *str)
{
	int		fd;
	char	**ho;
	int		i;
	int		j;

	fd = open(str, O_RDONLY);
	i = ft_strlen2(str);
	ho = malloc(sizeof(char *) * (i + 1));
	if (!ho)
		return (NULL);
	j = 0;
	while (j < i)
	{
		ho[j] = get_next_line(fd);
		j++;
	}
	ho[j] = NULL;
	close(fd);
	return (ho);
}
