/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedfousi <pedfousi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:21:27 by pedfousi          #+#    #+#             */
/*   Updated: 2025/03/05 17:29:09 by pedfousi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*allocate_line(char *line, size_t line_len)
{
	line = (char *)malloc(line_len + 1);
	if (!line)
		return (NULL);
	return (line);
}

static char	*read_to_buffer(int fd, char *buffer, size_t *bytes_read)
{
	*bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (*bytes_read <= 0)
		return (NULL);
	buffer[*bytes_read] = '\0';
	return (buffer);
}

static char	*append_char(char *line, size_t *line_len, char current_char)
{
	line = realloc(line, *line_len + 1);
	if (!line)
		return (NULL);
	line[*line_len] = current_char;
	(*line_len)++;
	return (line);
}

static char	*finalize_line(char *line, size_t line_len)
{
	line = realloc(line, line_len + 1);
	if (!line)
		return (NULL);
	line[line_len] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	static size_t	buffer_pos = 0;
	static ssize_t	bytes_read = 0;
	char			*line ;
	size_t			line_len;
	char			current_char;

	*line = NULL;
	line_len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	while (1)
	{
		if (buffer_pos >= (size_t)bytes_read)
		{
			if (!read_to_buffer(fd, buffer, &bytes_read))
				return (line_len > 0 ? line : NULL);
			buffer_pos = 0;
		}

		current_char = buffer[buffer_pos++];
		line = append_char(line, &line_len, current_char);
		if (!line)
			return (NULL);

		if (current_char == '\n')
			break;
	}

	return (finalize_line(line, line_len));
}
