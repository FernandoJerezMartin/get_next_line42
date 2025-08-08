/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fjerez-- <fjerez--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:25:10 by fjerez--          #+#    #+#             */
/*   Updated: 2025/08/08 20:03:46 by fjerez--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_from_fd(int fd, char **general_buffer)
{
	char	*local_buffer;
	char	*aux;
	int		bytes_read;

	local_buffer = malloc(BUFFER_SIZE + 1);
	if (!local_buffer)
		return (-1);
	bytes_read = 1;
	while (!ft_strchr(*general_buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, local_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(local_buffer);
			free(*general_buffer);
			*general_buffer = NULL;
			return (-1);
		}
		local_buffer[bytes_read] = '\0';
		aux = ft_strjoin(*general_buffer, local_buffer);
		free(*general_buffer);
		*general_buffer = aux;
	}
	free(local_buffer);
	return (0);
}

static char	*get_line_buffer(char *general_buffer)
{
	int		i;
	char	*line;

	if (!general_buffer[0])
		return (NULL);
	i = 0;
	while (general_buffer[i] && general_buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (general_buffer[i] && general_buffer[i] != '\n')
	{
		line[i] = general_buffer[i];
		i++;
	}
	if (general_buffer[i] == '\n')
		line[i] = '\n';
	i++;
	line[i] = '\0';
	return (line);
}

char	*aim_next(char *general_buffer)
{
	int		i;
	int		j;
	char	*new_buffer;

	i = 0;
	j = 0;
	while (general_buffer[i] && general_buffer[i] != '\n')
		i++;
	if (!general_buffer[i])
	{
		free(general_buffer);
		return (NULL);
	}
	new_buffer = malloc(ft_strlen(general_buffer) - i + 1);
	if (!new_buffer)
		return (NULL);
	i++;
	while (general_buffer[i])
		new_buffer[j++] = general_buffer[i++];
	new_buffer[j] = '\0';
	free(general_buffer);
	return (new_buffer);
}

char	*get_next_line(int fd)
{
	static char	*general_buffer = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
	}
	if (read_from_fd(fd, &general_buffer) == -1)
	{
		return (NULL);
	}
	if (!general_buffer)
	{
		free(general_buffer);
		general_buffer = NULL;
		return (NULL);
	}
	line = get_line_buffer(general_buffer);
	general_buffer = aim_next(general_buffer);
	return (line);
}
/* Falta por implementar:
		- Solucionar fallos
*/
