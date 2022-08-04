/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfanzaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:26:39 by hfanzaou          #+#    #+#             */
/*   Updated: 2021/12/04 22:38:10 by hfanzaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*c;

	if (!s1)
		s1 = ft_strdup("\0");
	i = ft_strlen(s1) + ft_strlen(s2);
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (c == NULL)
		return (0);
	j = 0;
	while (s1[j])
	{
		c[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		c[j + i] = s2[i];
		i++;
	}
	c[j + i] = '\0';
	free(s1);
	return (c);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_cmp(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
	{
		free(s);
		return (ft_strdup("\0"));
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	i = 0;
	c = malloc(sizeof(char) * (len + 1));
	if (!c)
		return (0);
	while (i < len)
	{
		c[i] = s[start + i];
		i++;
	}
	c[i] = '\0';
	free(s);
	return (c);
}

char	*ft_strdup(char *s)
{
	char	*dst;
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (dst == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
