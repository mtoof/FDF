/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoof <mtoof@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:07:18 by mtoof             #+#    #+#             */
/*   Updated: 2023/04/03 14:09:17 by mtoof            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*found_new_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*trim_buffer(char *buffer)
{
	int		index_buffer;
	int		index_nextline;
	char	*next_line;

	index_buffer = 0;
	while (buffer[index_buffer] && buffer[index_buffer] != '\n')
		index_buffer++;
	if (!buffer[index_buffer])
	{
		free(buffer);
		return (NULL);
	}
	next_line = ft_calloc((ft_strlen(buffer) - index_buffer + 1),
			sizeof(char *));
	if (!next_line)
		return (NULL);
	index_buffer++;
	index_nextline = 0;
	while (buffer[index_buffer])
		next_line[index_nextline++] = buffer[index_buffer++];
	free(buffer);
	return (next_line);
}

static char	*read_and_stash(int fd, char *buffer)
{
	int		readed_char;
	char	*stash;
	char	*tmp;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	readed_char = 1;
	stash = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!stash)
		return (NULL);
	while (readed_char > 0)
	{
		readed_char = read(fd, stash, BUFFER_SIZE);
		if (readed_char == -1)
			return (NULL);
		stash[readed_char] = 0;
		tmp = ft_strjoin(buffer, stash);
		free(buffer);
		buffer = tmp;
		if (ft_strchr(stash, '\n'))
			break ;
	}
	free(stash);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_and_stash(fd, buffer);
	if (!buffer)
		return (NULL);
	line = found_new_line(buffer);
	buffer = trim_buffer(buffer);
	return (line);
}
