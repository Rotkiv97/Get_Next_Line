/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguidoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:04:15 by vguidoni          #+#    #+#             */
/*   Updated: 2022/11/02 16:04:23 by vguidoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

ssize_t	read(int fd, void *buf, size_t count);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_free_join(char *stash, char *buff);
char	*ft_estrazione_new_line(char *stash);
char	*ft_clear_stash(char *stash, char *line);
char	*ft_lettura(int fd, char *stash);
char	*get_next_line(int fd);
int		ft_ripiego(char *buff, char *stash);

#endif
