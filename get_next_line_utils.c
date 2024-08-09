/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:03:50 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/02 16:03:54 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
		a++;
	return (a);
}

char	*ft_strchr(char *s, int c)
{
	char	k;
	int		y;

	y = 0;
	k = (unsigned char)c;
	while (s[y] != '\0')
	{
		if (s[y] == k)
			return ((char *)(&s[y]));
		y++;
	}
	if (k == '\0')
		return ((char *)(&s[y]));
	return (NULL);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*l;
	unsigned int	p;
	unsigned int	k;

	p = 0;
	k = 0;
	l = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!l)
		return (NULL);
	while (s1[p] != '\0')
	{
		l[p] = s1[p];
		p++;
	}
	while (s2[k] != '\0')
	{
		l[p + k] = s2[k];
		k++;
	}
	l[p + k] = '\0';
	return (l);
}

char	*ft_strdup(const char *s)
{
	char	*y;
	size_t	f;

	f = 0;
	y = malloc(ft_strlen((char *)s) + 1);
	if (!y)
		return (NULL);
	while (s[f] != '\0')
	{
		y[f] = s[f];
		f++;
	}
	y[f] = '\0';
	return (y);
}

int	ft_ripiego(char *buff, char *stash)
{
	if (stash[0] == 0 && stash)
	{
		free(buff);
		free(stash);
		return (1);
	}
	return (0);
}
