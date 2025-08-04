/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fernando <fernando@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:25:10 by fernando          #+#    #+#             */
/*   Updated: 2025/08/04 23:27:22 by fernando         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    int     pos;
    char    *line;

    pos = 0;

    if (!fd && BUFFER_SIZE <= 0)
    {
        return (NULL);
    }
    while (fd && pos < BUFFER_SIZE)
    {
        line = read_to_buffer(fd, BUFFER_SIZE);
    }
}

static char *read_to_buffer(int fd, char *buffer)
{
    
}