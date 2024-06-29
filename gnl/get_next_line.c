/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snourry <snourry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 09:28:06 by snourry           #+#    #+#             */
/*   Updated: 2022/12/09 00:57:20 by snourry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

static char	*gnl_read(int fd, char *backup)
{
	char		*buffer;
	long long	i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	i = 1;
	*buffer = 0;
	while (!gnl_strchr(buffer, '\n') && i)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
		{
			free(buffer);
			buffer = 0;
			return (0);
		}
		buffer[i] = 0;
		backup = gnl_strjoin(backup, buffer, i);
	}
	free(buffer);
	buffer = 0;
	return (backup);
}

static char	*gnl_free_backup(char *backup, size_t i)
{
	char	*new;
	size_t	j;

	if (!i)
	{
		free(backup);
		backup = 0;
		return (0);
	}
	new = malloc(sizeof(char) * (gnl_strlen(backup) - i + 1));
	if (!new)
		return (0);
	j = 0;
	while (backup[i])
		new[j++] = backup[i++];
	new[j] = 0;
	free(backup);
	backup = 0;
	return (new);
}

static char	*gnl_get_line(char *backup)
{
	char	*line;
	size_t	i;

	if (!*backup)
		return (0);
	line = malloc(sizeof(char) * gnl_size(backup));
	if (!line)
		return (0);
	i = -1;
	while (++i, backup[i] && backup[i] != '\n')
		line[i] = backup[i];
	if (backup[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if ((fd < 0 || fd > 1023) && BUFFER_SIZE < 1)
		return (0);
	backup = gnl_read(fd, backup);
	if (!backup)
		return (0);
	line = gnl_get_line(backup);
	backup = gnl_free_backup(backup, gnl_size(backup) - 1);
	return (line);
}
