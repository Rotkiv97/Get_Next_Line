/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:03:15 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/02 16:03:21 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_join(char *stash, char *buff)
{
	char	*tmp;

	if (!stash)
	{
		stash = malloc(1);
		stash[0] = '\0';
	}
	tmp = ft_strjoin(stash, buff);
	free(stash);
	return (tmp);
}

char	*ft_estrazione_new_line(char *stash)
{
	char	*line;
	int		n;

	n = 0;
	if (stash == NULL)
		return (NULL);
	while (stash[n] != '\0' && stash[n] != '\n')
		n++;
	line = malloc(sizeof(char) * (n + 2));
	n = 0;
	while (stash[n] != '\n' && stash[n] != '\0')
	{	
		line[n] = stash[n];
		n++;
	}
	if (stash[0] == '\0' || stash == NULL)
	{
		free(line);
		return (NULL);
	}
	if (stash[n])
		line[n++] = '\n';
	line[n] = '\0';
	return (line);
}

char	*ft_clear_stash(char *stash, char *line)
{
	char	*tmp;
	int		l;
	int		y;

	l = 0;
	y = 0;
	while (stash[l] != '\n' && stash[l] != '\0')
		l++;
	tmp = malloc(sizeof(char) * (ft_strlen(stash) - (ft_strlen(line)) + 2));
	if (stash[l] != '\0')
		l++;
	while (stash[l] != '\0')
		tmp[y++] = stash[l++];
	tmp[y] = '\0';
	free(stash);
	if (tmp[0] == 0)
	{
		free(tmp);
		return (0);
	}
	return (tmp);
}

char	*ft_lettura(int fd, char *stash)
{
	char	*buff;
	int		k;

	k = 1;
	buff = malloc(sizeof(char) *(BUFFER_SIZE + 1));
	while (k)
	{	
		k = read(fd, buff, BUFFER_SIZE);
		if (k < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[k] = '\0';
		stash = ft_free_join(stash, buff);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	if (ft_ripiego(buff, stash))
		return (0);
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;
	size_t		count;

	count = 0;
	if ((fd < 0 || BUFFER_SIZE <= 0) || read(fd, &line, count) < 0)
	{	
		return (NULL);
	}
	stash = ft_lettura(fd, stash);
	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	line = ft_estrazione_new_line(stash);
	if (stash[0] == '\0' || stash == NULL)
	{
		free(stash);
		return (NULL);
	}
	stash = ft_clear_stash(stash, line);
	return (line);
}

int	main(int argc, char **argv)
{
    int		fd;
    char	*line;

    if (argc != 2)
    {
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("\033[31mError file\033[0m");
        return (1);
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("\033[32m%s\033[0m", line);
        free(line);
    }
	printf("\n");
    close(fd);
    return (0);
}
